/* Problem Description

Given an integer N, you write down a sequence of 2N ones. For each of the ones, you now want to assign either + or a - (2N assignments in total) so that the entire sequence can now be computed as a mathematical value.

For example, for a sequence with N=3, an assignment +--++- would look like (+1,−1,−1,+1,+1,−1).

You say that a sequence of assignments is good if at all points, the prefix sum of the sequence is non-negative. That is, formally, for all indices i(1≤i≤2N), the sum ∑ij=1Sj is non-negative. Further, the sum of the entire sequence, ∑2Nj=1Sj is equal to 0.

For example, say N=3, then, a valid sequence would be ++-+-- which denotes a sequence of the form (+1,+1,−1,+1,−1,−1). However, the sequence +--++- is invalid because at index i=3, we have the prefix sum as −1 which is negative.

Output all such good sequences in lexicographical order. Here, we say a sequence s is lexicographically smaller than sequence t if at the first index at which s and t differ, say i, s[i]=+ but t[i]=−. In other words, we consider + to have a smaller value than -.

Input Format

The only line of input contains a single integer N that denotes that you need to construct a sequence of 2N ones.

Input constraints

    1 ≤ N ≤ 10

Output Format

For each test-case: output valid sequences in lexicographical order with each sequence in a new line. Output each sequence as a string consisting of + and - characters (not space-separated).

Sample Input
3

Sample Output

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
#include <string.h>

void generate_good_sequence(int n, int prefix_sum, char *sequence, int len)
{
    if (prefix_sum < 0)
    {
        return;
    }

    if (len == 2 * n)
    {
        if (prefix_sum == 0)
        {
            printf("%s\n", sequence);
        }
        return;
    }

    char plus[2] = "+";
    char minus[2] = "-";

    /* strcat() modifies the original string, rather than creating a new one. This means that on each recursive call, the same string is being modified, rather than creating a new string each time. Additionally, the variable sequence is not being reset between recursive calls, causing the string to become longer and longer on each call. This causes the program to hang in an infinite loop. */

    char new_sequence[100];
    snprintf(new_sequence, sizeof(new_sequence), "%s%s", sequence, plus);
    generate_good_sequence(n, (prefix_sum + 1), new_sequence, len + 1);

    snprintf(new_sequence, sizeof(new_sequence), "%s%s", sequence, minus);
    generate_good_sequence(n, (prefix_sum - 1), new_sequence, len + 1);

    /*  snprintf() is used to create new strings with the desired characters. */
}

int main()
{
    int n;
    scanf("%d", &n);
    char sequence[100] = "";
    generate_good_sequence(n, 0, sequence, 0);
    return 0;
}
