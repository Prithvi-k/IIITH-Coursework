#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int A, N, C, count = 0, flag = 0, decimal;
        scanf("%d %d %d", &A, &N, &C);

        // A = A % N;
        // printf("A = %d\n", A);
        if (A < N)
        {
            A = (A * 10);
            // printf("A = %d\n", A);
            count++;
        }

        for (int j = 0; j < (N+10); j++)
        {

            decimal = (A / N);
            // printf("Decimal = %d\n", decimal);
            if (count != 0 && decimal == C)
            {
                printf("%d\n", count);
                flag = 1;
                break;
            }
            A = (A % N);
            // printf("A = %d\n", A);
            A = (A * 10);
            // printf("A = %d\n", A);
            count++;
        }
        if (flag == 0)
        {
            printf("-1\n");
        }
    }

    return 0;
}