#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void high_and_low (const char *strnum, char *result)
{
    const char *delimiter = " ";
    char *endptr;
    char string[1024];

    // Copy the input string to avoid modifying it
    strncpy(string, strnum, sizeof(string) - 1);
    string[sizeof(string) - 1] = '\0'; // Null-terminate the string

    char *token = strtok(string, delimiter);

    long number = strtol(token, &endptr, 10);
    
    long min_val = number;
    long max_val = number;

    if (token == NULL) 
    {
        // Handle empty input
        sprintf(result, "0 0");
        return;
    }

    if (*endptr != '\0') 
    {
        // Handle invalid first token
        sprintf(result, "0 0");
        return;
    }

    while (token != NULL) 
    {
        long char_to_number = strtol(token, &endptr, 10);

        if (char_to_number > max_val)
        {
            max_val = char_to_number;
        }

        if (char_to_number < min_val)
        {
            min_val = char_to_number;
        }

        token = strtok(NULL, delimiter);
    }

    // print your answer to <result> :
    sprintf(result, "%ld %ld", max_val, min_val);
}

int main()
{
    const char *number_string = "8 3 -5 42 -1 0 0 -9 4 7 4 -4";
    char result[50];

    high_and_low(number_string, result); 

    printf("%s", result);

    return 0;
}