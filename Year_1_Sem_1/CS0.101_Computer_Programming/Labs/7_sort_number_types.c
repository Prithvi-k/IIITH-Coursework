#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given a file containing numbers, write a program to create three files:
1. prime.txt - containing all the prime numbers
2. even.txt - containing all the even numbers
3. odd.txt - containing all the odd numbers
 */

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FILE *fp, *prime, *even, *odd;
    fp = fopen("7_file.txt", "r");
    prime = fopen("7_prime.txt", "w");
    even = fopen("7_even.txt", "w");
    odd = fopen("7_odd.txt", "w");

    if (fp == NULL || prime == NULL || even == NULL || odd == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    int n;
    while (fscanf(fp, "%d ", &n) != EOF)
    {

        if (n % 2 != 0)
        {
            fprintf(odd, "%d\n", n);
            if (isPrime(n))
            {
                fprintf(prime, "%d\n", n);
            }
        }
        else
        {
            fprintf(even, "%d\n", n);

            if (isPrime(n))
            {
                fprintf(prime, "%d\n", n);
            }
        }
    }

    fclose(fp);
    fclose(prime);
    fclose(even);
    fclose(odd);

    return 0;
}