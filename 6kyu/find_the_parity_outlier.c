#include <stddef.h>
#include <stdio.h>

int find_outlier(const int values[/* count */], size_t count)
{
  int odd_counter = 0;
  int even_counter = 0;
  
  for (size_t i = 0; i < count; i++)
  {
    if (values[i] % 2 != 0)
    {
      odd_counter++;
      
    } else {
      
      even_counter++;
    }
  }
  
  for (size_t j = 0; j < count; j++)
  {
    if (odd_counter > even_counter && values[j] % 2 == 0)
    {
      return values[j];
      
    } else if (even_counter > odd_counter && values[j] % 2 != 0) {
      
      return values[j];
    }
  }
  
  return 0;
}

int main() 
{
    // Example input for find_outlier
    int values[] = {2, 4, 6, 8, 10, 3}; // An array containing integers
    size_t count = sizeof(values) / sizeof(values[0]);

    // Find the outlier
    int outlier = find_outlier(values, count);

    // Print the result for find_outlier
    printf("Array: {2, 4, 6, 8, 10, 3}\n");
    printf("Outlier: %d\n", outlier);

    return 0;
}