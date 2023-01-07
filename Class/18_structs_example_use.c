#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

float distance_from_origin(Point p)
{
    return sqrt((p.x * p.x) + (p.y * p.y));
}

Point move_point(Point p, float angle, float len)
{
    Point p2 = {
        .x = p.x + len * cos((2 * 3.14 * angle) / 360.0),
        .y = p.y - len * sin((2 * 3.14 * angle) / 360.0)};
    return p2;
}

int main()
{
    Point p = {.x = 3, .y = 4};
    printf("X coordinate of p is %d\n", p.x);
    printf("Y coordinate of p is %d\n", p.y);
    printf("Distance of p from origin is %f\n", distance_from_origin(p));

    Point p2 = move_point(p, 20, 1);
    printf("X coordinate of p2 is %d\n", p2.x);
    printf("Y coordinate of p2 is %d\n", p2.y);
    printf("Distance of p2 from origin is %f\n", distance_from_origin(p2));

    return 0;
}