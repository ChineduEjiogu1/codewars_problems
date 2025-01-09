#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int minimun_index = step;

        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[minimun_index])
            {
                minimun_index = i;
            }
        }
        swap(&array[minimun_index], &array[step]);
    }
}

void sort_array(size_t n, int *arr)
{
    // sort the contents of arr

    int *sorted_odd_array = (int *)malloc(n * sizeof(int));
    int odd_counter = 0;
    size_t i = 0;
    size_t j = 0;

    for (; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sorted_odd_array[odd_counter++] = arr[i];
        }
    }

    selection_sort(sorted_odd_array, odd_counter);

    int odd_index = 0;

    for (; j < n; j++)
    {
        if (arr[j] % 2 != 0)
        {
            arr[j] = sorted_odd_array[odd_index++];
        }
    }
}

int main() 
{
    int array[] = {5, 3, 2, 8, 1, 4, 11};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using sort_array
    sort_array(size, array);

    printf("Sorted Array (Odds sorted, Evens unchanged): ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}