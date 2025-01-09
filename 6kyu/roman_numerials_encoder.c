#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void roman_numeral_converter(int number, char **result)
{
    if (number <= 0)
    {
        *result = strdup("Invalid number");
        return;
    }

    *result = (char *)malloc(1); // Start with an empty string
    (*result)[0] = '\0';         // Null-terminate the empty string

    while (number > 0)
    {
        if (number >= 1000)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "M");
            number -= 1000;
        }
        else if (number >= 900)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "CM");
            number -= 900;
        }
        else if (number >= 500)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "D");
            number -= 500;
        }
        else if (number >= 400)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "CD");
            number -= 400;
        }
        else if (number >= 100)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "C");
            number -= 100;
        }
        else if (number >= 90)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "XC");
            number -= 90;
        }
        else if (number >= 50)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "L");
            number -= 50;
        }
        else if (number >= 40)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "XL");
            number -= 40;
        }
        else if (number >= 10)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "X");
            number -= 10;
        }
        else if (number >= 9)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "IX");
            number -= 9;
        }
        else if (number >= 5)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "V");
            number -= 5;
        }
        else if (number >= 4)
        {
            *result = (char *)realloc(*result, strlen(*result) + 3);
            strcat(*result, "IV");
            number -= 4;
        }
        else if (number >= 1)
        {
            *result = (char *)realloc(*result, strlen(*result) + 2);
            strcat(*result, "I");
            number -= 1;
        }
    }
}

char *solution(int n)
{
    char *result = NULL;

    roman_numeral_converter(n, &result);

    return result; // Return the dynamically allocated string
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    char *roman = solution(number);
    printf("Roman Numeral: %s\n", roman);

    free(roman); // Free the allocated memory

    return 0;
}
