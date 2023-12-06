#include <stdio.h>

int jealous(int x, int count)
{
    int num = x;
    if ((x % 10) == x)
    {
        count++;
        return count;
    }
    else
    {
        int max = 0, digit = 0;
        while (x != 0)
        {
            digit = x % 10;
            if (digit >= max)
            {
                max = digit;
            }
            x /= 10;
        }
        count++;
        return jealous((num - max), count);
    }
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);

    int result = jealous(n, count);
    printf("%d\n", result);
    return 0;
}
