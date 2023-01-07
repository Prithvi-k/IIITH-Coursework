/* Problem Description

You are playing a game with some stones where you need to divide the stones into two groups such that the difference between the sum of the stones weight is minimum.

Formally, given a set of stones S
, you need to divide the stones into two groups S1 and S2 such that S1∩S2 is ϕ (which denotes the empty set), S1∪S2=S and if sum1 and sum2 represent the sum of weights in group S1 and S2 respectively, then you need to minimize |sum1−sum2|

.
Input Format

The first line of input contains a single integer denoting the number of stones N

.

The following line contains N

space separated integers denoting the weights of the stones.
Input constraints

    1≤N≤20

1≤Si≤109

Output Format

Output on a single line the minimum difference for the optimal division

Sample Input

3
5 10 21

Sample Output

6

Note

Explanation for sample input 1:

    Divide the stones into groups (5,10)

and (21) */

#include <stdio.h>

int min_diff(int diff, int n, int array[n], int start, int end)
{
    if (start == end)
    {
        if ((diff - array[start]) < 0)
        {
            return array[start];
        }
        else
        {
            diff -= array[start];
            return diff;
        }
    }
    else if (end == 1)
    {
        int greatest = array[1];
        int second_greatest = array[0];
        if ((diff - (greatest - second_greatest)) < 0)
        {
            diff += (greatest - second_greatest);
        }
        else
        {
            diff -= (greatest - second_greatest);
        }
        return diff;
    }

    else
    {
        int greatest = array[end];
        int second_greatest = array[end - 1];
        if ((diff - (greatest - second_greatest)) < 0)
        {
            diff += (greatest - second_greatest);
        }
        else
        {
            diff -= (greatest - second_greatest);
        }
        return min_diff(diff, n, array, start, (end - 2));
    }
}

int main()
{
    int n, temp, result, diff = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = (j + 1); k < n; k++)
        {
            if (arr[j] >= arr[k])
            {
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }

    result = min_diff(diff, n, arr, 0, (n - 1));
    printf("%d\n", result);

    return 0;
}