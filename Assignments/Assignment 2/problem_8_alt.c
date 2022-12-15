#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int A, N, C, count = 1, whole, flag = 0;
        float rem;
        scanf("%d %d %d", &A, &N, &C);

        A = A / N;

        for (int j = 0; j < N; j++)
        {
            rem = ((float)A / (float)N);
            // printf("rem_initial: %f\n", rem);
            rem = rem * 10;
            // printf("rem: %f\n", rem);
            if (count == 1)
            {
                if (((int)rem) == C)
                {
                    flag = 1;
                    // printf("1");
                    printf("%d\n", count);
                }
            }
            else
            {
                whole = (int)rem;
                // printf("whole: %d\n", whole);
                whole = whole % 10;
                // printf("whole: %d\n", whole);
                if (whole == C)
                {
                    // printf("2");
                    flag = 1;
                    printf("%d\n", count);
                }
            }
            count++;
        }
        if (count > N && flag == 0)
        {
            printf("-1\n");
        }
    }

    return 0;
}