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

int factorial(int n)
{
    return ((n == 1) ? 1 : (n * factorial(n - 1)));
}

bool unique_permutation(char *str, int start, int end)
{
    // Checks if character at current index is present throughtout the rest of the string
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

int count_characters_in_string(int n, char *str, int *count_alphabets)
{
    for (int i = 0; i < 26; i++)
    {
        count_alphabets[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        char element = str[i];
        int element_ascii = (int)str[i];
        count_alphabets[(element_ascii - 97)] += 1;
    }
}

int count_password_permutations(int n, int *count_alphabets)
{
    int perms = factorial(n);
    for (int i = 0; i < 26; i++)
    {
        if (count_alphabets[i] != 0)
        {
            perms /= factorial(count_alphabets[i]);
        }
    }
    return perms;
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
            if (unique_permutation(str, start, i))
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

    int password_count = 0, n = strlen(a);
    int count_alphabets[26];
    count_characters_in_string(n, a, count_alphabets);
    password_count = count_password_permutations(n, count_alphabets);
    printf("%d\n", password_count);
    password_permutations(a, 0, n - 1);

    return 0;
}