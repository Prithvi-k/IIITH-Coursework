#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

void move_point(Point *p, float angle, float len)
{
    p->x += len * cos((2 * 3.14 * angle) / 360.0);
    p->y -= len * sin((2 * 3.14 * angle) / 360.0);
}

int main()
{
    Point p = {.x = 3, .y = 4};

    return 0;
}