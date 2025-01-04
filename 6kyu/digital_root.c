#include <stdio.h>

int split_digits_and_add(int num) 
{
    int sum = 0;
    
    while (num > 0) 
    {
        int digit = num % 10;  // Extract the last digit
        sum += digit;
        num /= 10;        // Remove the last digit
    }

    return sum;
}

int digital_root(int n) {
  // 
  if (n < 10) {
        return n;
    }

    return digital_root(split_digits_and_add(n));
}

int main() 
{
    // Test numbers
    int test_numbers[] = {0, 7, 16, 942, 132189, 493193};
    size_t count = sizeof(test_numbers) / sizeof(test_numbers[0]);

    // Loop through the test numbers and calculate their digital root
    for (size_t i = 0; i < count; i++) 
    {
        int number = test_numbers[i];
        int result = digital_root(number);
        printf("Digital root of %d is %d\n", number, result);
    }

    return 0;
}