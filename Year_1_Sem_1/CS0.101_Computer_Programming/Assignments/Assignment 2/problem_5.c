#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N, M, rec, count = 0, max_rec = 0;
        scanf("%d %d", &N, &M);

        int arr[M + 1];

        for (int q = 0; q < (M + 1); q++)
        {
            arr[q] = 0;
        }

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &rec);
            arr[rec] += 1;
        }

        int max = arr[0];

        for (int k = 0; k < (M + 1); k++)
        {
            if (arr[k] > max)
            {
                max = arr[k];
            }
        }

        for (int m = 0; m < (M + 1); m++)
        {
            if (arr[m] == max)
            {
                count++;
                max_rec = m;
            }
        }

        if (count == 1)
        {
            printf("%d\n", max_rec);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}