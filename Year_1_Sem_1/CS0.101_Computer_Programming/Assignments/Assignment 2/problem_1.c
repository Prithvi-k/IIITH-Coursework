#include <stdio.h>

int main()
{
    int problems, X, Y;
    scanf("%d", &problems);

    for (int i = 0; i < problems; i++)
    {
        scanf("%d %d", &X, &Y);
        printf("%d\n", (X * 5) + (Y * 3));
    }

    return 0;
}