#include <stddef.h>
#include <stdio.h>

float finduniq(const float *nums, size_t n)
{
    float number_1 = 0;
    float number_2 = 0;

    number_1 = nums[0];
    number_2 = nums[1];

    for (size_t i = 2; i < n; i++)
    {
        if (number_1 == number_2)
        {
            if (nums[i] != number_1)
            {
                return nums[i];
            }
            
        } else {
            
            if (nums[i] == number_1)
            {
                return number_2;

            } else {

                return number_1;
            }
        }
    }

    return 0;
}

int main()
{
    float array[] = {0, 0, 0.55, 0, 0};

    int size = sizeof(array) / sizeof(array[0]);

    float result = finduniq(array, size);

    printf("%.1f", result);
}