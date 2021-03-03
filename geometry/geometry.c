#include "geometry.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double sqr(double x)
{
    return pow(x, 2);
}

double length(Point first, Point second)
{
    double l = sqrt(sqr(second.x - first.x) + sqr(second.y - first.y));
    return l;
}

double circlePeri(Circle circle)
{
    return 2 * M_PI * circle.radius;
}

double circleArea(Circle circle)
{
    return sqr(circle.radius) * M_PI;
}

bool isCircle(Circle circle)
{
    if (circle.radius <= 0)
        return false;
    return true;
}