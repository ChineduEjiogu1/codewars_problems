#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *repeat_str(size_t count, const char *src)
{
    int src_length = strlen(src);
    int new_length = src_length * count;

    int j = 0;

    char *multiplied_string = (char *)malloc(new_length + 1);


    for (int k = 0; k < count; k++)
    {
        for (int i = 0; src[i] != '\0'; i++) 
        { 
            {
                multiplied_string[j++] = src[i];
            } 
        }      
    }

    multiplied_string[j] = '\0';

    return multiplied_string;
}

int main()
{
    const char *str = "hello";
    int repeat_count = 3;

    char *multiplied_str = repeat_str(repeat_count, str);
    printf("%s\n", multiplied_str);

    free(multiplied_str);
    
    return 0;
}