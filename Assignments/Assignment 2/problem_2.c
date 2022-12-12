#include <stdio.h>

int main()
{
    int n, M, S, O, oreoShakes;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &M, &S, &O);
        oreoShakes = 0;

        if (M < 1 || S < 1 || O < 2)
        {
            oreoShakes = 0;
        }
        else
        {
            while (M > 0 && S > 0 && O > 0)
            {
                M -= 1;
                S -= 1;
                O -= 2;
                oreoShakes += 1;
            }
        }
        printf("%d\n", oreoShakes);
    }

    return 0;
}
