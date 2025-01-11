#include <stdio.h>
#include <math.h>

int split_digits_and_power(int number, int power)
{
    int sum = 0;
    int digit = 0;
    int divisor = 1;

    while (number / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor > 0)
    {
       digit = number / divisor;
       sum += pow(digit, power);
       number %= divisor;
       divisor /= 10;
       power++;
    }

    return sum;
}

int digPow(int n, int p)
{
    int sum = split_digits_and_power(n, p);

    return (sum % n == 0) ? (sum / n) : -1;
}

int main()
{
    int number = 0;
    int starting_power = 0;

    printf("%s", "Please enter a number: ");
    scanf("%d", &number);

    printf("%s", "Please enter a positive power (number): ");
    scanf("%d", &starting_power);

    printf("%d", digPow(number, starting_power));
}