#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance? 

*/

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    int N, C;
    scanf("%d %d", &N, &C);

    int *stalls = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &stalls[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (stalls[i] > stalls[j])
            {
                int temp = stalls[i];
                stalls[i] = stalls[j];
                stalls[j] = temp;
            }
        }
    }

    int l = 0, r = stalls[N - 1], ans, mid;
    
    

    
}