#include <stdio.h>

int gcd(int a, int b)
{
    return (b) == 0 ? a : gcd(b, a % b);
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("gcd(%d, %d) = %d\n", x, y, gcd(x, y));

    return 0;
}