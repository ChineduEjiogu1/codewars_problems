#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int find_odd(size_t length, const int *array)
{
    int minimum_value = array[0];

    for (size_t i = 1; i < length; i++)
    {
        if (array[i] <minimum_value)
            minimum_value = array[i];
    }

    int offset = (minimum_value < 0) ? -minimum_value : 0;

    int range = 0;

    for (size_t j = 0; j < length; j++)
    {
        if (array[j] + offset > range)
        {
            range = array[j] + offset;
            printf("Range is: %d\n", range);
        }
    }

    int *freq = (int *)calloc(range + 1, sizeof(int));

    for (size_t k = 0; k < length; k++)
    {
        freq[array[k] + offset]++;
        printf("%d %d\n", array[k], freq[array[k] + offset]);
        printf("The offest is: %d\n", array[k] + offset);
    }

    printf("\n");

    for (size_t i = 0; i < length; i++)
    {
        if (freq[array[i] + offset] % 2 == 1)
        {
            free(freq);
            return array[i];
        }
    }

    free(freq);

    return 0;
}

int main()
{
    const int array[] = {20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5};
    int size = sizeof(array) / sizeof(array[0]);

    printf("The result is: %d", find_odd(size, array));
}