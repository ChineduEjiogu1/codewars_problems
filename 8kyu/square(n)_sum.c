#include <stddef.h>
#include <stdio.h>

int square_sum(const int values[/* count */], size_t count)
{
  int sum = 0;
  
  for (int i = 0; i < count; i++)
  {
    sum += values[i] * values[i];
  }
  
	return sum;
  
}

int main() 
{
    // Define an array of integers
    int values[] = {1, 2, 3, 4, 5};

    // Get the size of the array
    size_t count = sizeof(values) / sizeof(values[0]);

    // Call the function to calculate the sum of squares
    int result = square_sum(values, count);

    // Print the result
    printf("The sum of squares is: %d\n", result);

    return 0;
}