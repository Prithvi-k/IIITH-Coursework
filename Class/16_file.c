#include <stdio.h>

int main()
{
    int arr[1] = {1};

    printf("%ld", sizeof(arr) / sizeof(arr[0]));

    return 0;
}