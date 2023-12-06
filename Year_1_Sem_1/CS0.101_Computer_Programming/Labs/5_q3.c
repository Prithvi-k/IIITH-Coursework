#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int k = 0; k < T; k++)
    {
        int sum = 0, n = 0, count = 0, x = 0;
        scanf("%d %d", &sum, &n);

        int denominations[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &denominations[i]);
        }

        for (int j = (n - 1); j >= 0; j--)
        {
            if ((sum / (denominations[j])) > 0)
            {
                x = sum / (denominations[j]);
                count += x;
                sum %= (denominations[j]);
            }
        }

        printf("%d\n", count);
    }

    return 0;
}