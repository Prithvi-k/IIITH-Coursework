#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // malloc returns a void pointer with 4n bytes of memory

    int *b = (int *)malloc(n); // malloc returns a void pointer with n bytes of memory

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    /*

    a[i] == *(a + (i * sizeof(type)))
    type -> datatype of the array

    */

    // NOT COVERED IN LAB
    // a[i] ~*(a + i) ~*(i + a) ~i[a] // all are valid
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        printf("%d ", *(a + i));
        printf("%d ", *(i + a));
        printf("%d ", i[a]);
        printf("\n");
    }

    return 0;
}