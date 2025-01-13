#include <stdio.h>

int split_array_and_find_equal_sum(const int *array, int array_size)
{
    int total_sum = 0;
    int left_sum = 0;

    for (int i = 0; i < array_size; i++)
    {
        total_sum += array[i];
    }

    for (int i = 0; i < array_size; i++)
    {
        total_sum -= array[i];

        if (left_sum == total_sum)
        {
            return i;
        }

        left_sum += array[i];
    }

    return -1;
}

int find_even_index(const int *values, int length)
{
    return split_array_and_find_equal_sum(values, length);
}

int main()
{
    int array[] = {1, 2, 3, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    int split_at_index = find_even_index(array, size);

    if (split_at_index != -1)
    {
        printf("Split at index: %d\n", split_at_index);

        printf("Left side: {");
        for (int j = 0; j < split_at_index; j++)
        {
            printf("%d%s", array[j], (j < split_at_index - 1) ? ", " : "");
        }

        printf("}\nRight side: {");
        for (int j = split_at_index + 1; j < size; j++)
        {
            printf("%d%s", array[j], (j < size - 1) ? ", " : "");
        }
        printf("}\n");
    }
    else
    {
        printf("No equal halves found.\n");
    }

    return 0;
}