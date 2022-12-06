#include <stdio.h>

int main()
{
    int n;

    printf("Please enter a number: ");
    scanf("%d", &n); // get number of elements in array rrquired

    int arr[n]; // initialise array
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2]; // F(i) = F(i-1) + F(i-2), by definition
    }

    for (int j = 0; j < n; j++)
    {
        printf("%d \n", arr[j]); // iterate through index and print out values within array
    }

    printf("\n");

    return 0;
}