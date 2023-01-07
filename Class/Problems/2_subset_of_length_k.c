#include <stdio.h>

int subset(int n, int k, int S[n], int x)
{
	if (k == 0 || k == 1) {
        for (int d = 0; d < n; d++) {
            printf("%d ", S[d]);
        }
        printf("\n");
    } else if (x >= n || k > n - x) {
        return 0;
    } else {
        S[x] = 1;
        subset(n, k - 1, S, x + 1);
        S[x] = 0;
        subset(n, k, S, x + 1);
    }
}

int main()
{
	int n, k;
	scanf("%d %d", &k, &n);

	int S[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", S[i]);
	}
	
	subset(n, k, S, 0);
	return 0;
}
