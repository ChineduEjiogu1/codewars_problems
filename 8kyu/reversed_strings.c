#include <string.h>
#include <stdio.h>

char *strrev (char *string)
{
  
  int left = 0;
  int right = strlen(string) - 1;
  
  while (left < right)
  {
    int temp = string[left];
    string[left] = string[right];
    string[right] = temp;
    
    left++;
    right--;

  }

  return string; // reverse the string in place and return it

}

int main() {
    // Define a string to be reversed
    char input_string[] = "hello, world!";

    // Print the original string
    printf("Original string: %s\n", input_string);

    // Reverse the string
    char *reversed_string = strrev(input_string);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed_string);

    return 0;
}