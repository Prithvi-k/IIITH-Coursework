#include <stdio.h>

int sort(int x, int arr[x])
{
    if (sizeof(arr) / sizeof(arr[0]) == 1)
    {
        return arr;
    }

    int min = 1000000, index = x + 1, temp = 0, alt[x-1];

    for (int j = 0; j < x; j++)
    {
        if (arr[j] <= min)
        {
            min = arr[j];
            index = j;
        }
    }

    temp = arr[index];
    arr[index] = arr[0];
    arr[0] = temp;

    for (int i = 0; i < x; i++)
    {
        
    }
    

    sort(x-1, )
}

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    sort(n, array);

    for (int k = 0; k < n; k++)
    {
        printf("%d ", array[k]);
    }

    return 0;
}