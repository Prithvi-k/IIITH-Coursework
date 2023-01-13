/* Problem Description

Given an integer N
, you write down a sequence of 2N ones. For each of the ones, you now want to assign either + or a - (2N

assignments in total) so that the entire sequence can now be computed as a mathematical value.

For example, for a sequence with N=3
, an assignment +--++- would look like (+1,−1,−1,+1,+1,−1

).

You say that a sequence of assignments is good if at all points, the prefix sum of the sequence is non-negative. That is, formally, for all indices i
(1≤i≤2N), the sum ∑ij=1Sj is non-negative. Further, the sum of the entire sequence, ∑2Nj=1Sj is equal to 0

.

For example, say N=3
, then, a valid sequence would be ++-+-- which denotes a sequence of the form (+1,+1,−1,+1,−1,−1). However, the sequence +--++- is invalid because at index i=3, we have the prefix sum as −1

which is negative.

Output all such good sequences in lexicographical order. Here, we say a sequence s
is lexicographically smaller than sequence t if at the first index at which s and t differ, say i, s[i]=+ but t[i]=−

. In other words, we consider + to have a smaller value than -.
Input Format

The only line of input contains a single integer N
that denotes that you need to construct a sequence of 2N

ones.
Input constraints

    1≤N≤10

Output Format

For each test-case: output valid sequences in lexicographical order with each sequence in a new line. Output each sequence as a string consisting of + and - characters (not space-separated).
Sample Input
Copy

3

Sample Output
Copy

+++---
++-+--
++--+-
+-++--
+-+-+-

Note

Explanation for sample input 1:

    Check example in problem statement
 */

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int total_permutations = 1;
    for (int i = 1; i <= n; i++)
    {
        total_permutations *= 2;
    }

    char arr[total_permutations][2 * n];
    for (int i = 0; i < total_permutations; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            arr[i][j] = '+';
        }
    }

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < total_permutations; j++)
        {
            if (j % (2 * index) == 0)
            {
                for (int k = 0; k < index; k++)
                {
                    arr[j][k] = '-';
                }
            }
        }
        index = index * 2 + 1;
    }

    for (int i = 0; i < total_permutations; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}