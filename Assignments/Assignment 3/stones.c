#include <stdio.h>

int MinSum(int n, int arr[n], int sum, int sumCalc)
{
    if (n == 0)
    {
        return ((sum - sumCalc) - sumCalc) > 0 ? ((sum - sumCalc) - sumCalc) : (-((sum - sumCalc) - sumCalc));
    }
    else
    {
        int sum1 = MinSum(n - 1, arr, sum, sumCalc + arr[n - 1]);
        int sum2 = MinSum(n - 1, arr, sum, sumCalc);
        return sum1 < sum2 ? sum1 : sum2;
    }
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int result = MinSum(n, arr, sum, 0);
    printf("%d\n", result);

    return 0;
}