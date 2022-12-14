#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int C, count = 0;
        long double A, N;
        scanf("%Lf %Lf %d", &A, &N, &C);

        long double div = (A / N) * 10;

        while (count <= 10000001)
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
                break;
            }

            if (count == (10000000))
            {
                printf("-1\n");
                break;
            }
            div = div - (int)div;
            count++;
        }
    }

    return 0;
}