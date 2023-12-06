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
            sum += arr[j]; // finding total sum of all elements of array
        }

        /*
        Switching `1` to `-1` or `-1` to `1`
        essentially changes the value of sum by 2
        hence if the sum itself is not divisible by 2,
        no changes can make the sum = 0
         */
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