#include <stdio.h>
#include <stdlib.h>
int MAX_CACHE = 100;

// Naive Fibonacci
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

// With caching
int fib_cache(int n, int *cache)
{
    if (n < MAX_CACHE && cache[n] != -1)
    {
        return cache[n];
    }
    else
    {
        cache[n] = fib_cache(n - 1, cache) + fib_cache(n - 2, cache);
        return cache[n];
    }
}

int main(int argc, char const *argv[])
{

    // for (int i = 0; i < 45; i++) {
    //     printf("%d ", fib(i));
    // }

    int *cache = malloc(sizeof(int) * MAX_CACHE);

    for (int i = 0; i < MAX_CACHE; i++)
    {
        cache[i] = -1;
    }
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 0; i < 45; i++)
    {
        printf("%d ", fib_cache(i, cache));
    }
    printf("\n");
    free(cache);
    return 0;
}
