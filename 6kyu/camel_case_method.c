#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char *string)
{
    int i = 0, j = 0;
  
    for (; string[i]; i++)
    {
        if (string[i] != ' ')
        {
          string[j++] = string[i];
        }
    }
  
  string[j] = '\0';
  
}

char *camel_case(const char *s)
{
  
  int string_length = strlen(s);
  char *copy_of_string = (char *)malloc(string_length + 1);
  strcpy(copy_of_string, s);
  
  for (int i = 0; copy_of_string[i] != '\0'; i++)
  {
    if (copy_of_string[i] == ' ')
    {
      copy_of_string[i + 1] = toupper(copy_of_string[i + 1]);
    }
     copy_of_string[0] = toupper(copy_of_string[0]);
  }
  
  remove_spaces(copy_of_string);
  
  return copy_of_string;
  
}

int main() 
{
    const char *input = "hello world example text"; // Example input

    // Convert to camel case
    char *camel_result = camel_case(input);

    // Print the results
    printf("Input: %s\n", input);
    printf("Camel Case: %s\n", camel_result);

    // Free the allocated memory
    free(camel_result);

    return 0;
}
