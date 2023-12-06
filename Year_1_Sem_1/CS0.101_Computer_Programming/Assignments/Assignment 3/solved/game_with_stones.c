#include <stdio.h>

long int MinimumDifference(long int n, long int arr[n], long int totalSum, long int subsetSum)
{
    // Base Case
    // if n == 0, we take difference between the sum of subsets
    // if subsets are a1 and a2 with sum s1 and s2
    // s2 = subsetSum (say)
    // then, s1 = totalSum - subsetSum
    if (n == 0)
    {
        if (((totalSum - subsetSum) - subsetSum) > 0)
        {
            return ((totalSum - subsetSum) - subsetSum);
        }
        else
        {
            return -((totalSum - subsetSum) - subsetSum);
        }
    }
    // if n > 0
    // find difference of sums between subset with last element
    // and difference of sums between subset without last element
    // we do this to find all possible subsets of given set
    else
    {
        long int sum1 = MinimumDifference(n - 1, arr, totalSum, subsetSum + arr[n - 1]);
        long int sum2 = MinimumDifference(n - 1, arr, totalSum, subsetSum);
        if (sum1 < sum2)
        {
            return sum1;
        }
        else
        {
            return sum2;
        }
    }
}

int main()
{
    long int n, totalSum = 0, result = 0;
    scanf("%ld", &n);

    long int arr[n];
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
        totalSum += arr[i];
    }

    result = MinimumDifference(n, arr, totalSum, 0);
    printf("%ld\n", result);

    return 0;
}