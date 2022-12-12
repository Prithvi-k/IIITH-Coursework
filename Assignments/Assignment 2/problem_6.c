#include <stdio.h>

/* Problem Description
You find yourself in DSM class. Since you’re bored, you decide to look for your friends. You first notice
that the classroom appears as a grid of size N × M that is, a grid with N rows and M columns. You
represent the classroom as a N × M binary matrix (a matrix consisting of only 0s and 1s) where, a cell
with ‘1’ denotes a friend and ‘0’ otherwise. You are currently on cell (R, C) (cell at row R and column
C).
You now want to find out the friend whose Manhattan distance from you is the minimum possible. If
there are no such friends, then output −1 instead. However, if there are multiple friends at the same
minimum distance, then print the row and column of the one who is lexicographically smallest.
Manhattan distance between two cells (a, b) and (c, d) is defined as |a − c| + |b − d|.
A cell (a, b) is lexicographically smaller than the cell (c, d) if either of the following is true:
• a < c
• a = c and b < d
Input Format
The first line of input contains a single integer denoting the number of test-cases T . The description of
each test-case follows:
For each test-case:
The first line of each test-case contains four space separated integers N, M, R, C. Here, N and M denote
the number of rows and columns respectively in the classroom. R, C denotes the row and column where
you are seated.
Then, N lines follow where the ith line describes the ith row of the classroom. It contains M space-
separated integers where the jth integer being ‘1’ denotes that the student at the cell (i, j) is a friend
and ‘0’ otherwise */

int main()
{
    int T, N, M, R, C;
    scanf("%d", T);

    for (int i = 0; i < T; i++)
    {
        /* code */
    }

    return 0;
}