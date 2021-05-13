#include <libgeom/geometry.h>
#define _USE_MATH_DEFINES
#include <math.h>

double get_circle_perimeter(Circle* circle)
{
    return 2 * M_PI * circle->radius;
}

double get_circle_area(Circle* circle)
{
    return M_PI * pow(circle->radius, 2);
}