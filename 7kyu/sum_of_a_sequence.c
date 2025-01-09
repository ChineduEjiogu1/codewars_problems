#include <stdio.h>

unsigned sequence_sum(unsigned start, unsigned end, unsigned step)
{
    if (start > end)
        return 0;

    return start + sequence_sum(start + step, end, step);
}

int main()
{
    unsigned start = 2;
    unsigned end = 6;
    unsigned step = 2;

    unsigned result = sequence_sum(start, end, step);

    printf("%d", result); 
} 