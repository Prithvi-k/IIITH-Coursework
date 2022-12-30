#include <stdio.h>

long int f(long int x)
{
    return ((x * x) + (2 * x) + 3);
}

long int main()
{
    long int num = 0;
    scanf("%ld", &num);

    printf("%ld", (f(f(f(num) + num) + f(f(num)))));
    return 0;
}