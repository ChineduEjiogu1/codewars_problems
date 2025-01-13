#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool xo(const char* str) 
{
    int ascii_count[256] = {0}; // Initialize frequency array

    // Process each character in the string
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char lowercase_char = tolower((unsigned char)str[i]); // Convert to lowercase
      
        if (lowercase_char == 'x' || lowercase_char == 'o') {
            ascii_count[(unsigned char)lowercase_char]++;
        }
    }

    // Compare counts of 'x' and 'o'
    return ascii_count['x'] == ascii_count['o'];
}

int main() 
{
    const char *test1 = "XxOo";        // Equal count
    const char *test2 = "xoxoXO";      // Equal count
    const char *test3 = "XoooxX";      // Unequal count
    const char *test4 = "abcd";        // No 'x' or 'o'

    printf("Test 1 (\"%s\"): %s\n", test1, xo(test1) ? "True" : "False");
    printf("Test 2 (\"%s\"): %s\n", test2, xo(test2) ? "True" : "False");
    printf("Test 3 (\"%s\"): %s\n", test3, xo(test3) ? "True" : "False");
    printf("Test 4 (\"%s\"): %s\n", test4, xo(test4) ? "True" : "False");

    return 0;
}