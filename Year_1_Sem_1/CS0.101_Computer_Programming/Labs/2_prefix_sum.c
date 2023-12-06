#include <stdio.h>

int main()
{
    int n;

    printf("Pleas enter the length of the required array: ");
    scanf("%d", &n);

    int A[n], B[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            B[0] = A[0];
        }
        else
        {
            B[j] = B[j - 1] + A[j];
        }
    }

    printf("\n");

    for (int k = 0; k < n; k++)
    {
        printf("%d ", A[k]);
    }

    printf("\n");

    for (int l = 0; l < n; l++)
    {
        printf("%d ", B[l]);
    }

    printf("\n");

    return 0;
}