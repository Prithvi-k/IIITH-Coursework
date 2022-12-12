#include <stdio.h>

int main()
{
    int T, N;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        int arr[N], sum = 0, result = 0;

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }

        if ((sum % 2) != 0)
        {
            result = -1;
        }
        else
        {
            if (sum < 0)
            {
                result = (-sum) / 2;
            }
            else
            {
                result = sum / 2;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}