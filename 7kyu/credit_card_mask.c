#include <stdio.h>
#include <string.h>

char *maskify (char *masked, const char *string)
{
  
  int length = strlen(string);
  
  if (length <= 4) 
  {
        strcpy(masked, string);
        return masked; 
  }
    
  for (int i = 0; i < length - 4; i++)
  {
    masked[i] = '#';
  }
  
  for (int i = length - 4; i < length; i++) 
  {
      masked[i] = string[i];
  }
  
  masked[length] = '\0';
  
  // write to masked
	return masked; // return it
}

int main() 
{
    const char *test1 = "1234567890";       // Long enough to be masked
    const char *test2 = "1234";             // No masking required
    const char *test3 = "12";               // No masking required
    const char *test4 = "CreditCard12345";  // Mixed character test
    char masked[50];                        // Buffer for masked result

    printf("Test 1: Original: %s, Masked: %s\n", test1, maskify(masked, test1));
    printf("Test 2: Original: %s, Masked: %s\n", test2, maskify(masked, test2));
    printf("Test 3: Original: %s, Masked: %s\n", test3, maskify(masked, test3));
    printf("Test 4: Original: %s, Masked: %s\n", test4, maskify(masked, test4));

    return 0;
}