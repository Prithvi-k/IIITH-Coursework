#include <stdio.h>

int find_element(int n, int arr[n], int index, int x, int position)
{
    position++;
    if (arr[index] == x) // index represents index which will iterate over length of array
    {
        return position;
    }
    else if (position == n)
    {
        return -1;
    }
    else
    {
        return find_element((n - 1), arr, (index + 1), x, position);
    }

    return x;
}

int main()
{
    int n, x, result, position = 0, index = 0;
    scanf("%d", &n); // length of array
    scanf("%d", &x); // element to find

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    result = find_element(n, array, index, x, position);
    printf("%d\n", result);

    return 0;
}