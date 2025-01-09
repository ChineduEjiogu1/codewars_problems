#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//solution must allocate all required memory
//and return a free-able buffer to the caller.

char *disemvowel(const char *str)
{
  int length = strlen(str);
  int i = 0, j = 0;
  
  char *modifiable_char = (char *)malloc(length + 1);
  
  if (modifiable_char == NULL)
  {
    return NULL;
  }
  
  for (; i < length; i++)
  {
    
    char current_char = str[i];
    
    if (strchr("AEIOUaeiou", current_char) == NULL)
    {
      modifiable_char[j++] = current_char;
    }
  }
  
   modifiable_char[j] = '\0';
  
  return modifiable_char;
}

int main() 
{
    const char *input = "This is a test string to remove vowels!";
    printf("Original String: %s\n", input);

    // Call the disemvowel function
    char *result = disemvowel(input);

    printf("Disemvoweled String: %s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}