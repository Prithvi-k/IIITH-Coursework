#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N, K, x_i, y_i, count_quad_1 = 0, count_quad_2 = 0, count_quad_3 = 0, count_quad_4 = 0;
        scanf("%d %d", &N, &K);

        for (int j = 0; j < N; j++)
        {
            scanf("%d %d", &x_i, &y_i);
            if (x_i > 0)
            {
                if (y_i > 0)
                {
                    count_quad_1++;
                }
                else
                {
                    count_quad_4++;
                }
            }
            else
            {
                if (y_i > 0)
                {
                    count_quad_2++;
                }
                else
                {
                    count_quad_3++;
                }
            }
        }
        if (((count_quad_1 + count_quad_2) <= K) || ((count_quad_2 + count_quad_3) <= K) || ((count_quad_3 + count_quad_4) <= K) || ((count_quad_1 + count_quad_4) <= K))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}