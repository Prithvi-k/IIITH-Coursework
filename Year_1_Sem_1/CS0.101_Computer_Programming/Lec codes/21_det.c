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
            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k < i)
                    {
                        A[j - 1][k] = M[j][k];
                    }
                    else if (k > i)
                    {
                        A[j - 1][k - 1] = M[j][k];
                    }
                }
            }
            s += pow(-1, i % 2) * M[0][i] * det(n - 1, A);
        }
        return s;
    }
}

int main(int argc, char const *argv[])
{
    int M[2][2] = {{1, 2}, {5, 6}};
    printf("%d\n", det(2, M));
    return 0;
}
