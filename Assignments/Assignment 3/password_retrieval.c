/*
Problem Description

You forgot the password of your phone and you want to retrieve it. The only information you have is that the password is some rearragement of text T

.

Therefore, given text T
, your task is to generate all possible unique passwords that can be formed by re-arranging the characters of T

. You need to output these passwords in alphabetical order.
Input Format

The first and only line of input contains the text T
. Each character is between a to z

.
Input constraints

    1≤|T|≤8

Output Format

On the first line, output the number of different passwords that can be formed, say s
. This is followed by s

lines containing all possible passwords in alphabetical order.

Sample Input
aba

Sample Output

3
aab
aba
baa
 */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *a, int l, int r)
{
    if (l == r)
    {
        printf("%s", a);
        printf("%c", ' ');
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

int main()
{
    char a[100];
    scanf("%s", a);
    int n = strlen(a);
    permute(a, 0, n - 1);
    return 0;
}