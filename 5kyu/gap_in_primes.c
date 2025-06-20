#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void sieve_algo(bool *array, long long size)
{
    int starting_prime = 2;
    long long current_prime = 0;
    
    array[0] = false;
    array[1] = false;

    for (int i = starting_prime; i <= size; i++)
    {
        array[i] = true;
    } 
    
    for (int i = starting_prime; i <= size; i++) 
    {   
      if (array[i] == true) 
      {
        current_prime = i;
    
        for (int j = 2; j * current_prime <= size; j++) 
        {
            array[j * current_prime] = false;
        }
      }
    }
}

long long *collect_primes(long long m, long long n, int *prime_count)
{
    int sieve_size = n + 1;
    bool *sieve_array = (bool *)malloc((sieve_size) * sizeof(bool));

    int prime_counter = 0;
    int j = 0;

    if (!sieve_array)
    {
        return NULL;
    }

    sieve_algo(sieve_array, sieve_size);

    for (int i = m; i < sieve_size; i++)
    {
        if (sieve_array[i] == true)
        {
            prime_counter++;
        }
    }

    long long *result_array = (long long *)malloc((prime_counter) * sizeof(long long));

    if (!result_array) 
    {
        free(sieve_array);
        return NULL;
    }

    for (int i = m; i < sieve_size; i++)
    {
        if (sieve_array[i] == true)
        {
            result_array[j++] = i;
        }
    }

    *prime_count = prime_counter;
    return result_array;
}

long long *gap(int g, long long m, long long n) 
{  
    int prime_counter = 0;
    long long *primes = collect_primes(m, n, &prime_counter);

    if (primes == NULL) return NULL;

    long long *result = (long long *)malloc(2 * sizeof(long long));

    if (prime_counter == 0)
    {
        result[0] = 0;
        result[1] = 0;
    }

    for (int i = 0; i < prime_counter - 1; i++)
    {
        if (primes[i + 1] - primes[i] == g)
        {
            result[0] = primes[i];
            result[1] = primes[i + 1];
            free(primes);
            return result;
        }
        }

    result[0] = 0;
    result[1] = 0;
    free(primes);
    return result;
}

int main()
{
    printf("Test 1: gap(2, 5, 7) = ");
    long long *result1 = gap(2, 5, 7);
    printf("[%lld, %lld]\n", result1[0], result1[1]);
    
    printf("Test 2: gap(2, 5, 5) = ");
    long long *result2 = gap(2, 5, 5);
    printf("[%lld, %lld]\n", result2[0], result2[1]);
    
    printf("Test 3: gap(4, 130, 200) = ");
    long long *result3 = gap(4, 130, 200);
    printf("[%lld, %lld]\n", result3[0], result3[1]);
    
    return 0;
}