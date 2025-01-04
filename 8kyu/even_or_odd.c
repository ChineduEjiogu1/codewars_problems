#include <stdio.h>

const char* even_or_odd(int number)
{
  // return a statically allocated string,
  // for example a string literal
  
  if (number % 2 == 0)
  {
    return "Even";
    
  } else {
    
    return "Odd";
  }
  
}

int main() 
{
    // Define test numbers
    int numbers[] = {0, 1, 2, 3, 4, 5, -6, -7};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);

    // Loop through the numbers and test the function
    for (size_t i = 0; i < count; i++) 
    {
        printf("Number: %d is %s\n", numbers[i], even_or_odd(numbers[i]));
    }

    return 0;
}