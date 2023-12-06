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
            oreoShakes = 0; // if ingredients not sufficient
        }
        // takes least of M, S, O (constraint)
        else if (M < S && M < (O / 2))
        {
            oreoShakes = M;
        }
        else if (S < M && S < (O / 2))
        {
            oreoShakes = S;
        }
        else
        {
            oreoShakes = (O / 2);
        }

        printf("%d\n", oreoShakes);
    }

    return 0;
}
