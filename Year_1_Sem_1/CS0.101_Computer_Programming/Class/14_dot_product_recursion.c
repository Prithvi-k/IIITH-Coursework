#include <stdio.h>

int dot(int n, int a[n], int b[n])
{
    if (n == 1)
    {
        return a[0] * b[0];
    }
    else
    {
        return dot(n, a[0, n / 2], b[0, n / 2]) + dot(n, a[n / 2, n], b[n / 2, n]);
    }
}

int main()
{
    int u[4] = {1, 1, 1, 1}, v[4] = {-1, -1, -1, -1};

    printf("%d\n", dot(4, u, v));

    return 0;
}