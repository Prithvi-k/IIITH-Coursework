#include <stdio.h>

int main()
{
    int n, max_score = 0;

    scanf("%d", &n);

    int A[n], B[n], C[n], Courses[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        B[i] = scanf("%d", &B[i]);
    }

    for (int i = 0; i < n; i++)
    {
        C[i] = scanf("%d", &C[i]);
    }

    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            if (A[j] > B[j] && A[j] > C[j])
            {
                max_score += A[j];
                Courses[j] == 1;
                printf("%d .1", j);
            }
            else if (B[j] > A[j] && B[j] > C[j])
            {
                max_score += B[j];
                Courses[j] == 2;
                printf("%d .2", j);
            }
            else if (C[j] > A[j] && C[j] > B[j])
            {
                max_score += C[j];
                Courses[j] == 3;
                printf("%d .3", j);
            }
            else
            {
                max_score += A[j];
                Courses[j] == 0;
                printf("%d .4", j);
            }
        }
        else
        {
            if (A[j] > B[j] && A[j] > C[j] && (Courses[j - 1] != 1))
            {
                max_score += A[j];
                Courses[j] == 1;
                printf("%d .1", j);
            }
            else if (B[j] > A[j] && B[j] > C[j] && (Courses[j - 1] != 2))
            {
                max_score += B[j];
                Courses[j] == 2;
                printf("%d .2", j);
            }
            else if (C[j] > A[j] && C[j] > B[j] && (Courses[j - 1] != 3))
            {
                max_score += C[j];
                Courses[j] == 3;
                printf("%d .3", j);
            }
            else
            {
                max_score += A[j];
                Courses[j] == 0;
                printf("%d .4", j);
            }
        }
    }

    printf("Max Score = %d", max_score);

    return 0;
}