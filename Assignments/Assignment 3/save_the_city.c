/* Problem Description

You live in a town which can be represented as a grid of size 8×8
. Recently, there have been some reports of burglary in the town. You, as the mayor of the town want to appoint 8

guards to prevent them. Each guard lives in a single cell.

In order to have the maximum obervability, you want to assign them in such a way that no two of them share a common row or column. Further, there shouldn't be any pair of guards on the same diagonal (both main and alternate diagonals).

As an additional constraint, not all cells in the city have guard post. Call such cells as a "blocked cell". You can only assign guards to cells where guard post is present (non-blocked cells). Note that a blocked cell doesn't affect the placement of the guards in any way other than you not being to place a guard in that respective cell.

Your task is to find the total number of ways of placement of the gaurds such that they follow all the above constraints.
Input Format

The input consists of 8
lines, denoting the configuration of the cells in the town. Every line has 8 characters which denotes their configuration, whether they are free or blocked. (∗) stands for a blocked cell, that is a guard cannot be place in this cell whereas a (.)

stands for a free cell.
Output Format

Output on a single line the number of ways to place the guards.

Sample Input
Copy

*..*.*..
....*...
........
*.......
.*....**
*.**..*.
**.*.*..
.*.*....

Sample Output
Copy

2

Note

The only two possible sets of placements are (2,6,1,7,4,8,3,5) and (8,4,1,3,6,2,7,5).

These denote the positions where gaurds are placed from row 1 to 8.
*/

#include <stdio.h>

int check(int count, int n, char arr[n][n])
{
    if (n == 1)
    {
        if (arr[0][0] == '.')
        {
            count++;
            printf("%d", count);
        }
    }

    for (int i = 0; i < n; i++)
    {
        char A[n - 1][n - 1];
        for (int j = 1; j < n; j++)
        {
            if (arr[0][i] == '.')
            {
                for (int k = 0; k < n; k++)
                {
                    if (k < i)
                    {
                        A[j - 1][k] = arr[j][k];
                    }
                    else if (k > i)
                    {
                        A[j - 1][k - 1] = arr[j][k];
                    }
                }
            }
        }

        return check(count, n - 1, A);
    }
}

int main()
{
    int count = 0, n = 8;
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    check(count, n, arr);
    return 0;
}
