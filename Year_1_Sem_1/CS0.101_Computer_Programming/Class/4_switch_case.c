#include <stdio.h>

int main()
{
    int grade;

    scanf("%d", &grade);

    switch (grade) // analogous to if-elseif-else
    {
    case 4:
        printf("Excellent\n");
        break; // without break, next condition runs automatically (no check for next case)
    case 3:
        printf("Good\n");
        break;
    case 2:
        printf("Can be improved\n");
        break;
    case 1:
        printf("Poor\n");
        break;

    default:
        printf("Invalid grade\n");
        break;
    }
    return 0;
}