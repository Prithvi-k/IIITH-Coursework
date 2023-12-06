#include <stdio.h>

/*

Write a program which reads three integers and checks if they form pythogarean triplets.

*/

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a * a == (b * b + c * c) || b * b == (a * a + c * c) || c * c == (a * a + b * b) && a >= 0 && b >= 0 && c >= 0)
    {
        printf("%d, %d and %d form a Pythagorean Triplet\n", a, b, c);
    }
    else
    {
        printf("%d, %d and %d do not form a Pythagorean Triplet\n", a, b, c);
    }
    return 0;
}