#include <stdio.h>
#include <math.h>

int det(int n, int M[n][n])
{
    if (n == 1)
    {
        return M[0][0];
    }
    else
    {
        int s = 0;

        for (int i = 0; i < n; i++)
        {
            int A[n - 1][n - 1];
            // creating new array without first row and `i` column
            for (int j = 0; j < n - 1; j++)
            {
                for (int k = 0; k < n - 1; k++)
                {
                    if (k < i)
                    {
                        A[j][k] = M[j + 1][k];
                        // copies matrix as-is except for first row
                    }
                    else
                    {
                        A[j][k] = M[j + 1][k + 1];
                        // from ith column,
                        // we take elements of next column
                        // to skip the ith column
                    }
                }
            }
            s += pow(-1, i % 2) * M[0][i] * det(n - 1, A);
            // adds value of calculated determinant to common sum
            // considering sign
        }
        return s;
    }
}

int main()
{
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int M[n][n];
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
    printf("The determinant of the matrix is %d\n", det(n, M));
    return 0;
}