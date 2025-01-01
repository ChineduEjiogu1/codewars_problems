#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *range_extraction(const int *args, size_t n)
{
    if (n == 0)
    {
        char *empty_result = (char *)malloc(1);
        empty_result[0] = '\0';
        return empty_result; // Return an empty string for an empty array
    }

    int range_counter = 0;
    size_t j = 0;
    size_t i = 0;
    int initial_size = 100;
    int start = args[0]; // Start with the first number
    char *result_list = (char *)malloc(initial_size * sizeof(char));

    for (i = 1; i <= n; i++) // Loop through the array (note `i <= n` to handle last element correctly)
    {
        // Check if we're at the end or the current number breaks the range
        if (i == n || args[i] != args[i - 1] + 1)
        {
            if (range_counter >= 2)
            {
                // Append range "start-end"
                j += snprintf(result_list + j, initial_size - j, "%d-%d", start, args[i - 1]);
            }
            else if (range_counter == 1)
            {
                // Append two individual numbers separated by a comma
                j += snprintf(result_list + j, initial_size - j, "%d,%d", start, args[i - 1]);
            }
            else
            {
                // Append a single number
                j += snprintf(result_list + j, initial_size - j, "%d", start);
            }

            // Add a comma if we're not at the end
            if (i < n)
            {
                j += snprintf(result_list + j, initial_size - j, ",");
            }

            // Reset range and start a new potential range
            if (i < n)
            {
                start = args[i];
                range_counter = 0;
            }
        }
        else
        {
            // If the current number is part of the range, increment the counter
            range_counter++;
        }

        // Resize the buffer if needed
        if (j + 20 >= initial_size)
        {
            initial_size *= 2;
            result_list = (char *)realloc(result_list, initial_size);
        }
    }

    result_list[j] = '\0'; // Null-terminate the result string
    
    return result_list;
}

int main()
{
    const int range_of_number[] = {-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
    size_t size = sizeof(range_of_number) / sizeof(range_of_number[0]);

    char *result = range_extraction(range_of_number, size);

    printf("%s\n", result);

    free(result); // Free the allocated memory for the result string
    return 0;
}
