#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 

char *remove_spaces(const char *string)
{
  int counter = 0;
  
  int string_length = strlen(string);
  char *copy_of_string = (char *)malloc(string_length + 1 * sizeof(char));  
  strcpy(copy_of_string, string);
  
  for (int i = 0; copy_of_string[i] != '\0'; i++)
  {
    if (copy_of_string[i] != ' ')
    {
      copy_of_string[counter++] = copy_of_string[i];
    }
  }
  
  copy_of_string[counter] = '\0';
  
  return copy_of_string;
}

char *no_space(const char *str_in) {

    //  <----  hajime!
  
  int string_length = strlen(str_in);
  char *copy_of_str_in = (char *)malloc(string_length + 1 * sizeof(char));  
  strcpy(copy_of_str_in, str_in);
  
  return remove_spaces(copy_of_str_in);

}

int main() 
{
    // Define a string with spaces
    const char *input_string = "This is a test string with spaces";

    // Call the no_space function to remove spaces
    char *result_string = no_space(input_string);

    // Print the original and resulting strings
    printf("Original string: \"%s\"\n", input_string);
    printf("String without spaces: \"%s\"\n", result_string);

    // Free the dynamically allocated memory
    free(result_string);

    return 0;
}