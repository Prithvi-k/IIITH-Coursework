#include <stdio.h>

int rec_factorial(int n)
{
    /* if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * rec_factorial(n - 1));
    } */

    return (n == 0 ? 1 : (n * rec_factorial(n - 1)));
}

int main()
{
    int x = 0;
    scanf("%d", &x);

    printf("%d! = %d\n", x, rec_factorial(x));

    return 0;
}