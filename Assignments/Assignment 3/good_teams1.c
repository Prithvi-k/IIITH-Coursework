#include <stdio.h>

void print_team(int team[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", team[i]);
    }
    printf("\n");
}

void generate_teams(int players[], int n, int team[], int size, int index, int k)
{
    if (size == k)
    {
        print_team(team, size);
        return;
    }

    for (int i = index; i < n; i++)
    {
        team[size] = players[i];
        generate_teams(players, n, team, size + 1, i + 1, k);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int players[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &players[i]);
    }

    int team[k];
    generate_teams(players, n, team, 0, 0, k);
    return 0;
}
