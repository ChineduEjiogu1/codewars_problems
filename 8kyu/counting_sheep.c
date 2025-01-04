#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

size_t count_sheep(const bool sheep[/* count */], size_t count)
{
  int sheep_counter = 0;
  
  for (size_t i = 0; i < count; i++)
  {
      if (sheep[i] == true)
      {
        sheep_counter++;
        
      } else {
        
        continue;
        
      }
  }
  return sheep_counter;
}

int main() 
{
    // Define an array of booleans representing sheep
    bool sheep[] = {true, false, true, true, false, true, true, false, false, true};

    // Get the size of the array
    size_t count = sizeof(sheep) / sizeof(sheep[0]);

    // Call the function to count the number of sheep
    size_t sheep_count = count_sheep(sheep, count);

    // Print the result
    printf("Number of sheep: %zu\n", sheep_count);

    return 0;
}