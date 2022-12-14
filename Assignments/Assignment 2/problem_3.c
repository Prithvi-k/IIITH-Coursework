#include <stdio.h>

int main()
{
    int T, n;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        int arr[n], max = 0, shift = 0, new_arr[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        /*

        Taking sum of consecutive elements
        since first and last elements can be considered
        consecutive when shifted

         */
        for (int k = 0; k < (n - 1); k++)
        {
            int sum = arr[k] + arr[k + 1];
            if (sum > max)
            {
                max = sum;
                shift = n - (k + 1);
            }
            if ((arr[0] + arr[n - 1]) > max)
            {
                max = (arr[0] + arr[n - 1]);
                shift = 0;
            }
        }

        // creating new array with shift
        for (int l = 0; l < n; l++)
        {
            if (l < shift)
            {
                new_arr[l] = arr[n + l - shift];
            }
            else
            {
                new_arr[l] = arr[l - shift];
            }
        }

        printf("%d\n", max);
    }

    return 0;
}

/*

int main()
{
    int T, n;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        int arr[n], max = 0, shift = 0, new_arr[n];
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
                shift = n - (k + 1);
            }
            if ((arr[0] + arr[n - 1]) > max)
            {
                max = (arr[0] + arr[n - 1]);
                shift = 0;
            }
        }

        printf("shift: %d\n", shift);

        for (int l = 0; l < n; l++)
        {
            if (l < shift)
            {
                new_arr[l] = arr[n + l - shift];
            }
            else
            {
                new_arr[l] = arr[l - shift];
            }
        }

        printf("max sum: %d\n", max);

        for (int q = 0; q < n; q++)
        {
            printf("%d ", new_arr[q]);
        }
        printf("\n");
    }

    return 0;
} */