#include <stdio.h>

int add(int a, int b)
{
    int res = a + b;
    return res;
}

int increment(int a)
{
    a = a++;
    return a;
}

int main()
{
    int x, y;
    unsigned int blah = 4294967291;
    int m = 10;

    printf("Enter two numbers for addition : ");
    scanf("%d %d", &x, &y);

    int ans = add(x, y);
    printf("Sum of two numbers is : %d\n", ans);

    printf("Value of blah is : %d\n", blah);

    int arr[5] = {1, 2, 3, 4, 5};

    int z;
    printf("Enter a number to increment: ");
    scanf("%d", &z);
    z = increment(z);
    printf("Incremented number: %d\n", z);

    if (m = 11)
    {
        printf("m is 11\n");
    }
    else
    {
        printf("m is not 11\n");
    }

    return 0;
}