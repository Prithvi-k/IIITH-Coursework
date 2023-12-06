#include "stdio.h"

int factorial(int n)
{
    int product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}

int rec_fact(int n)
{
    // if (n==0){
    //     return 1;
    // } else {
    //     return n*rec_fact(n-1);
    // }

    return n == 0 ? 1 : n * rec_fact(n - 1);
}

int main()
{
    int n = 6;

    printf("%d\n", rec_fact(n));

    return 0;
}