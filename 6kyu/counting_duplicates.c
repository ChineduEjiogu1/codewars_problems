#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t duplicate_count(const char *text) 
{
    int count[256] = {0};  // Frequency array to count all characters
    size_t repeat_counter = 0;

    // Convert all characters to lowercase for case insensitivity and count frequencies
    for (int i = 0; text[i]; i++) {
        char ch = tolower(text[i]);  // Convert to lowercase for case insensitivity
        count[(unsigned char)ch]++;  // Increment the count of this character
    }

    // Count how many characters appear more than once
    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) {
            repeat_counter++;  // Increment repeat_counter if a character repeats
        }
    }

    return repeat_counter; // Return total count of repeated characters
}

int main() 
{
    char text[100];

    // User input for the string
    printf("Enter a string to check for duplicate characters: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove trailing newline if present
    text[strcspn(text, "\n")] = '\0';

    // Call duplicate_count and display the result
    size_t result = duplicate_count(text);
    printf("Number of duplicate characters: %zu\n", result);

    return 0;
}