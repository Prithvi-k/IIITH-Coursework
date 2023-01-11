#include <stdio.h>
#include <stdbool.h>

bool isSafe(int n, char matrix[n][n], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][column] == 1)
        {
            return false;
        }
    }
    for (int j = 0; j < column; j++)
    {
        if (matrix[row][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (matrix[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = column; i >= 0, j >= 0; i--, j++)
    {
        if (matrix[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool solveNQueen(int n, char matrix[n][n], int row, int count)
{
    for (int i = 0; i < n; i++)
    {
        if (isSafe(n, matrix, row, i) && matrix[row][i] == '.')
        {
            matrix[row][i] = 1;
            if (row == n - 1)
            {
                count++;
                return true;
            }
            else
            {
                if (solveNQueen(n, matrix, row + 1, count))
                {
                    count++;
                    return true;
                }
                else
                {
                    matrix[row][i] = 0;
                }
            }
        }
    }

    return false;
}

int main()
{
    int n = 8, count = 0, result = 0;
    char board[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            scanf("%c", &board[i][k]);
        }
    }

    result = solveNQueen(n, board, 0, count);
    printf("%d\n", result);

    return 0;
}