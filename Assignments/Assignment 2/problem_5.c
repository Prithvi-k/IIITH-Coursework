#include <stdio.h>

int main()
{
    int T, N, M;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        int arr[M], x;

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &x);
            arr[M] += x;
        }
        
        
    }

    return 0;
}