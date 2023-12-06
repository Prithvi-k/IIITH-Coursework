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
        int element_ascii = (int)element;
        count_alphabets[(element_ascii - 97)] += 1;
    }
    return 0;
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

void password_permutations(int n, int *count, char *str, int start, int end, char arrays[][n + 1])
{
    if (start == end)
    {
        strcpy(arrays[*count], str);
        (*count)++;
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
            password_permutations(n, count, str, start + 1, end, arrays);
            swap((str + start), (str + i));
        }
    }
}

int main()
{
    char a[10];
    scanf("%s", a);

    int password_count = 0, n = strlen(a), count = 0;
    // sort input string a
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

    int count_alphabets[26];
    char strings[factorial(n)][n + 1];
    count_characters_in_string(n, a, count_alphabets);
    password_count = count_password_permutations(n, count_alphabets);
    printf("%d\n", password_count);
    password_permutations(n, &count, a, 0, n - 1, strings);
    for (int i = 0; i < (count - 1); i++)
    {
        // sort each string in strings
        for (int j = i; j < count; j++)
        {
            char temp[n + 1];
            temp[n] = '\0';
            int c = strcmp(strings[i], strings[j]);
            if (c > 0)
            {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}