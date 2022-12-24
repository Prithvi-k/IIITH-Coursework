#include <stdio.h>
#include <stdlib.h>
int MAX_CACHE_SIZE = 100;

int regular_fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return regular_fibonacci(n - 1) + regular_fibonacci(n - 2);
    }
}

// caching fibonacci
// caching aka memoization
int caching_fibonacci(int n, int *cache)
{
    if (n < MAX_CACHE_SIZE && cache[n] != -1)
    {
        return cache[n];
    }
    else
    {
        cache[n] = caching_fibonacci(n - 1, cache) + caching_fibonacci(n - 2, cache);
        return cache[n];
    }
}

int main()
{
    int *cache = malloc(MAX_CACHE_SIZE * sizeof(int));
    for (int i = 0; i < MAX_CACHE_SIZE; i++)
    {
        cache[i] = -1;
    }
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 0; i < 45; i++)
    {
        printf("%d ", caching_fibonacci(i, cache));
        // takes 0.006 seconds
    }

    for (int j = 0; j < 45; j++)
    {
        printf("%d ", regular_fibonacci(j));
        // takes 12.1 seconds
    }

    printf("\n");
    return 0;
}