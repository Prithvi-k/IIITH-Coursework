#include <stdio.h>

void solve(int n, char *sequence, int pos, int sum)
{
    if (pos == 2 * n)
    {
        if (sum == 0)
        {
            printf("%s\n", sequence);
        }
        return;
    }

    if (sum < n - (pos / 2))
    {
        sequence[pos] = '+';
        solve(n, sequence, pos + 1, sum + 1);
    }

    if (sum > -n + (pos / 2))
    {
        sequence[pos] = '-';
        solve(n, sequence, pos + 1, sum - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char sequence[2 * n + 1];
    sequence[2 * n] = '\0';

    solve(n, sequence, 0, 0);

    return 0;
}
