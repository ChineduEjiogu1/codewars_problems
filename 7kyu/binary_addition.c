#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int *array, int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
}

int *number_to_binary(unsigned long long a, unsigned long long b)
{
    int *result = (int *)malloc(32 * sizeof(int));
    int j = 0;

    int n = a + b;

    if (n == 0)
    {
        result[0] = 0;
        result[1] = -1; // Sentinel value // Sentinel value to mark the end
        j = 1;

        return result;
    }

    while (n > 0)
    {
        result[j++] = n % 2;
        n /= 2;
    }

    reverse(result, j);

    result[j] = -1; // Sentinel value

    return result;
}

char *binary_add (unsigned a, unsigned b, char *binary)
{
    // write to the binary string and return it
    // Step 1: Perform the addition
    //unsigned sum = a + b;

    // Step 2: Use number_to_binary to convert the sum
    int *binary_digits = number_to_binary(a, b);

    // Step 3: Write the binary digits into the 'binary' string
    int i = 0;

    for (; binary_digits[i] != -1; i++)
    {
        binary[i] = '0' + binary_digits[i]; // Convert int to char ('0' or '1')
    }

    binary[i] = '\0'; // Null-terminate the string

    // Step 4: Clean up
    free(binary_digits);

    return binary;
}

int main()
{
    int a = 123;
    int b = 76;

    int n = a + b;

    char *complete_binary = (char *)malloc(32 * sizeof(char));

    char *result = binary_add(a, b, complete_binary);

    printf("Binary representation of %d is: %s\n", n, result);

    free(complete_binary); // Free allocated memory

    return 0;
}