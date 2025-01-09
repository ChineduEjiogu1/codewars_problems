//  do not allocate memory for return string
//  assign the value to the pointer "result"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_word(char *string)
{
    int left = 0;
    int right = strlen(string) - 1;

    // char *copy_of_string = (char *)malloc(right + 1);  // Allocate memory for the copy
    // strcpy(copy_of_string, string);
  
    while (left < right)
    {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;
      
        left++;
        right--;
    }
}


void extract_substrings(const char *sentence, char *result) 
{
    int i, j, len = strlen(sentence), result_index = 0;

    for (i = 0; i < len; i++) 
    {
        int word_len = 0;

        for (j = i; j < len && sentence[j] != ' '; j++) 
        {
            word_len++;
        }

        if (word_len >= 5) 
        {
            char *word = (char *)malloc(word_len + 1);

            strncpy(word, &sentence[i], word_len);
            word[word_len] = '\0';

            reverse_word(word);

            // Copy the reversed word into the result buffer
            strcpy(&result[result_index], word);
            result_index += word_len;

            free(word);
            
        } else {
            // Copy the word as it is into the result buffer
            strncpy(&result[result_index], &sentence[i], word_len);
            result_index += word_len;
        }

        if (sentence[j] == ' ') 
        {
            result[result_index++] = ' '; // Preserve spaces between words
        }

        i = j; // Move to the end of the current word
    }
    result[result_index] = '\0'; // Null-terminate the result
}

void spin_words(const char *sentence, char *result) 
{
    //  <----  hajime!
    extract_substrings(sentence, result); 
}


int main()
{
    const char *sentence = "This is a test string to check the function";
    char result[100]; // Ensure the buffer is large enough to hold the result

    spin_words(sentence, result);
    printf("%s\n", result);

    return 0;
}