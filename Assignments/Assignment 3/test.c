#include <stdio.h>
#include <stdbool.h>

long int count = 0;
int n = 8;
char city[8][8];

bool isSafe(int row, int col)
{

  // Check this row on left side
  for (int i = 0; i <= col - 1; i++)
  {
    if (city[row][i] == '1')
    {
      return false;
    }
  }

  // Check upper diagonal on left side
  for (int i = row, j = col; i >= 1 && j >= 1; i--, j--)
  {
    if (city[i][j] == '1')
    {
      return false;
    }
  }

  // Check lower diagonal on left side
  for (int i = row, j = col; j >= 1 && i <= n; i++, j--)
  {
    if (city[i][j] == '1')
    {
      return false;
    }
  }

  return true;
}

void placeGuards(int col)
{
  int i;
  if (col > n)
  {
    count++;
    return;
  }
  for (i = 0; i < n; i++)
  {
    if ((city[i][col] != '*')) // if the cell is not blocked and is safe
    {
      if (col == 0)
      {
        city[i][col] = '1';   // place a guard
        placeGuards(col + 1); // place guards for the next column
        city[i][col] = '.';   // if no guard can be placed in the next column, remove the guard from this column
      }
      else
      {
        if (isSafe(i, (col + 1)))
        {
          city[i][col] = '1';   // place a guard
          placeGuards(col + 1); // place guards for the next column
          city[i][col] = '.';   // if no guard can be placed in the next column, remove the guard from this column
        }
      }
    }
  }
}

int main()
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf(" %c", &city[i][j]);
    }
  }

  // printf("\n");
  // printf("\n");
  // printf("\n");
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     printf("%c", city[i][j]);
  //   }
  //   printf("\n");
  // }

  // printf("city[0][0] = %c\n", city[0][0]);
  // printf("city[3][1] = %c\n", city[3][1]);
  // printf("city[7][3] = %c\n", city[7][3]);

  // printf("isSafe(0,0) = %d\n", isSafe(0, 0));
  // printf("isSafe(3,1) = %d\n", isSafe(3, 1));

  // printf("is (0,3) containing '*'? %d\n", city[0][3] == '*');
  // printf("is (0,3) containing '.'? %d\n", city[0][3] == '.');

  placeGuards(0);
  printf("%ld\n", count);
  return 0;
}
