#include <stdio.h>

void sequence(int x)
{
    if (x == 1)
    {
        printf("1 ");
    }
    else
    {
        sequence(x - 1);
        printf("%d ", x);
        sequence(x - 1);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    sequence(num);
    return 0;
}