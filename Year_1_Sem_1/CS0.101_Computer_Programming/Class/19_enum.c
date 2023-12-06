#include <stdio.h>

typedef enum Weekday
{
    Sunday = 1, // `= 1` initialises value of Sunday to 1
    Monday,     // if not, by default first value is given 0
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday    
} Weekday;

int main()
{
    Weekday today = Wednesday;
    printf("Day %d\n", today + 1);
    printf("Size of enum variable is %d bytes\n", (int)sizeof(today));
    return 0;
}