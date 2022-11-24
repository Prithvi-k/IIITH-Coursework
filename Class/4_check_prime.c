#include <stdio.h>
#include <math.h> //using math library

int main()
{
    int n, i, flag = 1;

    printf("Please enter a number: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("1 is neither prime nor composite.\n");
    }
    else
    {
        for (i = 2; i < sqrt(n); i++) // it is sufficient to find factor until sqrt(n)
        {
            if (n % i == 0)
            {
                flag = 0; // helpful for problems requiring further uses of the fact that number is prime
                break;
            }
        }
    }

    if (flag == 1)
    {
        printf("%d is a prime number\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}