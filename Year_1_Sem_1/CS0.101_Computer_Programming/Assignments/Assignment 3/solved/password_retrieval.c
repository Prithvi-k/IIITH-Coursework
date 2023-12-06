/*
Problem Description

You forgot the password of your phone and you want to retrieve it. The only information you have is that the password is some rearragement of text T.

Therefore, given text T, your task is to generate all possible unique passwords that can be formed by re-arranging the characters of T. You need to output these passwords in alphabetical order.

Input Format

The first and only line of input contains the text T. Each character is between a to z.

Input constraints

    1≤|T|≤8

Output Format

On the first line, output the number of different passwords that can be formed, say s. This is followed by s lines containing all possible passwords in alphabetical order.

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
#include <stdbool.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool unique_character(char *str, int start, int end)
{
    // Checks if character at current index is present throughout the rest of the string
    for (int i = start; i < end; i++)
    {
        if (str[i] == str[end])
        {
            // If present, we skip the permutation for current character
            return true;
        }
    }
    // If not present, continue with permutation
    return false;
}

void count_password_permutations(char *str, int start, int end, int *count)
{
    if (start == end)
    {
        (*count)++;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            if (unique_character(str, start, i))
            {
                continue;
            }

            swap((str + start), (str + i));
            count_password_permutations(str, start + 1, end, count);
            swap((str + start), (str + i));
        }
    }
}

void password_permutations(char *str, int start, int end)
{
    if (start == end)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            if (unique_character(str, start, i))
            {
                continue;
            }

            swap((str + start), (str + i));
            password_permutations(str, start + 1, end);
            swap((str + start), (str + i));
        }
    }
}

int main()
{
    char a[10];
    scanf("%s", a);

    int count = 0, n = strlen(a);
    // sort input array
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    count_password_permutations(a, 0, (n - 1), &count);
    printf("%d\n", count);
    password_permutations(a, 0, (n - 1));

    return 0;
}