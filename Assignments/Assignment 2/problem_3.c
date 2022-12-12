#include <stdio.h>

int main()
{
    int T, n;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        int arr[n], max = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        for (int k = 0; k < (n - 1); k++)
        {
            int sum = arr[k] + arr[k + 1];
            if (sum > max)
            {
                max = sum;
            }
            if ((arr[0] + arr[n - 1]) > max)
            {
                max = (arr[0] + arr[n - 1]);
            }
        }
        printf("%d\n", max);
    }

    return 0;
}