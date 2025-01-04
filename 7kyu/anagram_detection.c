#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_anagram(const char *s1, const char *s2)
{
    int string_1_length = strlen(s1);
    int string_2_length = strlen(s2);

    int freq[256] = {0};

    if (string_1_length != string_2_length)
    {
        return false;
    }

    for (int i = 0; s1[i] != '\0'; i++)
    {
       
        freq[tolower(s1[i])]++;  
    }

    for (int j = 0; s2[j] != '\0'; j++)
    {   
        freq[tolower(s2[j])]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0) 
        {
            return false;
        }
    }

	return true;
}

int main()
{
    const char *word1 = "Creative";
    const char *word2 = "Reactive";

    const char *word3 = "foefet";
    const char *word4 = "toffee";

    const char *word5 = "Buckethead";
    const char *word6 = "DeathCubeK";

    const char *word7 = "Twoo";
    const char *word8 = "WooT";

    const char *word9 = "dumble";
    const char *word10 = "bumble";

    const char *word11 = "ound";
    const char *word12 = "round";

    const char *word13 = "apple";
    const char *word14 = "pale";

    if(is_anagram(word13, word14))
    {
        printf("%s", "Yes, it is an anagram");

    } else {

        printf("%s", "No, it's not an anagram");
  }
}