#include <stdio.h>

int main()
{
    int n, a = 0, b = 1, current;

    printf("Please enter a number: ");
    scanf("%d", &n); // get number of elements in array rrquired

    /* printf("%d\n", a);
    printf("%d\n", b); */

    for (int i = 0; i < n; i++)
    {
        current = a + b;
        if (i == (n - 1))
        {
            printf("%d\n", current);
        }

        a = b;
        b = current;
    }

    printf("\n");

    return 0;
}