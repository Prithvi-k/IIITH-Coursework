#include <stdio.h>

/*

Problem 1:
The CPro assignment-2 for students at IIIT-H has 8 problems. Bob finds the first 5 problems easy
and believes that he can finish them in X minutes each. On the other hand, he thinks that the last 3
problems are a little difficult and that it would take him Y minutes each to solve these questions.
Can you figure out the total number of minutes Bob will take to finish the entire assignment?

Input Format
The first line of input contains a single integer denoting the number of test-cases T . Then T lines follow:
For each test-case, the first and only line of input contains two space separated-integers X and Y.

*/

int main()
{
    int problems, X, Y;
    scanf("%d", &problems);

    for (int i = 0; i < problems; i++)
    {
        scanf("%d %d", &X, &Y);
        printf("%d\n", (X * 5) + (Y * 3));
    }

    return 0;
}