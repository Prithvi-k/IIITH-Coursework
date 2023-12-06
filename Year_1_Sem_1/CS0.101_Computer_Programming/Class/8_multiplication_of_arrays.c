#include <stdio.h>

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[3][4] = {{1, 2, 3, 4}, {2, 5, 7, 3}, {3, 6, 4, 2}};
    int result[2][4] = {};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += arr[i][k] * arr2[k][j];
            }
        }
    }

    for (int m = 0; m < 2; m++)
    {
        for (int n = 0; n < 4; n++)
        {
            printf("arr[%d](%d] = %d\n", m, n, result[m][n]);
        }
    }

    return 0;
}