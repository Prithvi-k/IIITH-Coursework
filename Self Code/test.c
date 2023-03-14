#include <stdio.h>
#include <stdbool.h>
#define N 4

bool solve(int m[N][N], int x, int y,int s[N][N]);

bool safe(int m[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1)
		return true;
	return false;
}

void soln(int s[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", s[i][j]);
		printf("\n");
	}
}

bool solve(int m[N][N], int x, int y, int s[N][N])
{
	if (x == N - 1 && y == N - 1 && m[x][y] == 1) {
		s[x][y] = 1;
		return true;
	}
	if (safe(m, x, y) == true) {
		if (s[x][y] == 1)
			return false;
		s[x][y] = 1;
		if (solve(m, x + 1, y, s) == true)
			return true;
		if (solve(m, x, y + 1, s) == true)
			return true;
		s[x][y] = 0;
		return false;
	}
	return false;
}

bool solmaze(int m[N][N])
{
	int s[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solve(m, 0, 0, s) == false) {
		printf("Soln not exist\n");
		return false;
	}
	soln(s);
	return true;
}

int main()
{
	int m[N][N] = { { 1, 1, 1, 1 },
					{ 1, 1, 1, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 0, 1, 1 } };
	solmaze(m);
	return 0;
}