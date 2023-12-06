#include <stdio.h>

// Track values using recursion tree
int fibonacci(int n)
{
    int a, b;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    a = fibonacci(n - 1);
    // printf("%d\n", a);
    b = fibonacci(n - 2);
    // printf("%d\n", b);
    return a + b;
}

int main()
{
    int i = fibonacci(100);
    printf("%d\n", i);
    return 0;
}