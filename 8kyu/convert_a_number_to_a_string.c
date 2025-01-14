#include <stdlib.h>
#include <stdio.h>

//  return a dynamically allocated C-string
//  this output will be freed by the tester

char *number_to_string(int number) 
{
    //  <----  hajime!
    int string_length = snprintf(NULL, 0, "%d", number);
    char *convert_to_string = (char *)malloc(string_length + 1 * sizeof(char));

    snprintf(convert_to_string, string_length + 1, "%d", number);    

    return convert_to_string;
}

int main()
{
    int number = 100;

    char *string = number_to_string(number); 
    printf("Integer: %d, String: %s\n", number, string); 
    free(string); // Free the allocated memory

    return 0;
}