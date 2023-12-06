#include <stdio.h>

int main()
{
    int n, count, l, r;

    printf("Please enter array length: ");
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

    printf("Number of queries: ");
    scanf("%d", &count);

    for (int j = 0; j < count; j++)
    {
        scanf("%d %d", &l, &r);

        if (r >= n || l >= n)
        {
            printf("query must be between 0 and %d\n", n - 1);
            printf("re-enter your query\n");
            scanf("%d %d", &l, &r);
        }

        int result = B[r] - B[l-1];
        printf("%d\n", result);
    }

    return 0;
}