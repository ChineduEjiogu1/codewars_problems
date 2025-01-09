#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** @param str: a C-string containing only lowercase letters and spaces (' ')
** @return:    a C-string allocated on the heap containing the highest scoring word of str
*/

// strtok() function to split the sentence into individual words 
// based on delimiters like spaces, commas, or periods.

char *highestScoringWord(const char *str)
{ 
  int str_length = strlen(str);
  char* buffer = (char*)malloc((str_length + 1) * sizeof(char));  // Ensure the buffer is large enough
  strncpy(buffer, str, str_length + 1);

  int current_score = 0;
  int maximum_score = 0;
  char* token = NULL;
  char* maximum_string = NULL;
  
  token = strtok(buffer, " ");

  while (token != NULL)
  {
    current_score = 0;
    
    for (int i = 0; token[i] != '\0'; i++)
    {
      current_score += token[i] - 'a' + 1 ;
    }
    
    if (current_score > maximum_score)
    {
        maximum_score = current_score;
        
        // Free the previous maximum_string if it's not NULL
        if (maximum_string != NULL)
        {
            free(maximum_string);
        }

        // Allocate memory for the new maximum_string and copy the token
        maximum_string = (char *)malloc(strlen(token) + 1);
    
        if (maximum_string == NULL) // Check for allocation failure
        {
            free(buffer);
            return NULL; // Handle allocation failure
        }
        strcpy(maximum_string, token);
    }
    
    token = strtok(NULL, " ");      
  }
  
  free(buffer); // Free the buffer after processing all tokens
  return maximum_string; 
}

int main() 
{
    const char *score_input = "the quick brown fox jumps over the lazy dog"; // Example input for highestScoringWord

    // Find the highest scoring word
    char *highest_word = highestScoringWord(score_input);

    // Print the results for highestScoringWord
    printf("Input: %s\n", score_input);
    printf("Highest Scoring Word: %s\n", highest_word);

    // Free the allocated memory for highestScoringWord
    free(highest_word);

    return 0;
}