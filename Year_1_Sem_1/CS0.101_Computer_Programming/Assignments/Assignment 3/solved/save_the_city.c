/* Problem Description

You live in a town which can be represented as a grid of size 8×8. Recently, there have been some reports of burglary in the town. You, as the mayor of the town want to appoint 8 guards to prevent them. Each guard lives in a single cell.

In order to have the maximum obervability, you want to assign them in such a way that no two of them share a common row or column. Further, there shouldn't be any pair of guards on the same diagonal (both main and alternate diagonals).

As an additional constraint, not all cells in the city have guard post. Call such cells as a "blocked cell". You can only assign guards to cells where guard post is present (non-blocked cells). Note that a blocked cell doesn't affect the placement of the guards in any way other than you not being to place a guard in that respective cell.

Your task is to find the total number of ways of placement of the gaurds such that they follow all the above constraints.

Input Format

The input consists of 8 lines, denoting the configuration of the cells in the town. Every line has 8 characters which denotes their configuration, whether they are free or blocked. (∗) stands for a blocked cell, that is a guard cannot be place in this cell whereas a (.) stands for a free cell.

Output Format

Output on a single line the number of ways to place the guards.

Sample Input

*..*.*..
....*...
........
*.......
.*....**
*.**..*.
**.*.*..
.*.*....

Sample Output

2

Note

The only two possible sets of placements are (2,6,1,7,4,8,3,5) and (8,4,1,3,6,2,7,5).

These denote the positions where guards are placed from row 1 to 8.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n = 8, solutions = 0;

bool is_okay(char arr[n][n], int row, int col)
{
    if (arr[row][col] == '*')
    {
        return false;
    }

    // check along row
    for (int i = 0; i < col; i++)
    {
        if (arr[row][i] == 'G')
        {
            return false;
        }
    }
    // check upper left diagonal
    int i = (row - 1), j = (col - 1);
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 'G')
        {
            return false;
        }
        i--;
        j--;
    }

    // check lower left diagonal
    int k = (row + 1), l = (col - 1);
    while (l >= 0 && k < n)
    {
        if (arr[k][l] == 'G')
        {
            return false;
        }
        k++;
        l--;
    }

    return true;
}

void PlaceGuards(char arr[n][n], int col)
{
    if (col == n)
    {
        solutions++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (is_okay(arr, i, col))
        {
            arr[i][col] = 'G';
            PlaceGuards(arr, (col + 1));
            arr[i][col] = '.';
        }
    }
}

int main()
{
    char city[n][n];
    for (int i = 0; i < n; i++)
    {
        char str[10];
        scanf("%s", str);
        for (int j = 0; j < n; j++)
        {
            city[i][j] = str[j];
        }
    }

    PlaceGuards(city, 0);
    printf("%d\n", solutions);
    return 0;
}