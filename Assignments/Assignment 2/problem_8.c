#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int C, count = 0, flag = 0;
        long double A, N;
        scanf("%Lf %Lf %d", &A, &N, &C);

        long double div = (A / N) * 10;
        div = div - (int)div;
        // printf("%Lf / %Lf = %Lf\n", A, N, div);

        while (count < N)
        {
            if (count == 0)
            {
                div = div;
            }
            else
            {
                div = div * 10;
            }

            if ((int)div == C)
            {

                printf("%d\n", (count + 1));
                flag = 1;
                break;
            }

            div = div - (int)div;
            count++;
        }
        if (flag == 0)
        {
            printf("-1\n");
        }
    }

    return 0;
}