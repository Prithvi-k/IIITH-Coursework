#include <stdio.h>

int main()
{
    int T, N, M, R, C;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d", &N, &M, &R, &C);
        // printf("N: %d, M: %d, R: %d, C: %d\n", N, M, R, C);
        int min_distance = 2500000, min_row = -1, min_column = -1;

        for (int j = 1; j < (N + 1); j++)
        {
            for (int k = 1; k < (M + 1); k++)
            {
                int element;
                scanf("%d", &element);
                if (element == 1)
                {
                    int distance = 0, dist_rows = 0, dist_columns = 0;
                    if ((j - R) > 0)
                    {
                        dist_rows = j - R;
                    }
                    else
                    {
                        dist_rows = R - j;
                    }
                    if ((k - C) > 0)
                    {
                        dist_columns = k - C;
                    }
                    else
                    {
                        dist_columns = C - k;
                    }
                    distance = dist_rows + dist_columns;

                    // printf("distance from (%d, %d) to (%d, %d): %d\n", R, C, j, k, distance);
                    if (distance < min_distance)
                    {
                        min_distance = distance;
                        min_row = j;
                        min_column = k;
                    }
                    else if (distance == min_distance)
                    {
                        if (j < min_row)
                        {
                            min_row = j;
                            min_column = k;
                        }
                        else if (j == min_row)
                        {
                            if (k < min_column)
                            {
                                min_row = j;
                                min_column = k;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
                // printf("min_distance: %d, min_row: %d, min_column: %d\n", min_distance, min_row, min_column);
            }
        }

        if (min_row == -1 && min_column == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n", min_row, min_column);
        }
    }

    return 0;
}