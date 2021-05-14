#include <ctest.h>
#include <libgeom/geometry.h>

CTEST(circle_area, get_area)
{
    Circle c1 = {.coords.x = 0, .coords.y = 0, .radius = 3};

    double expected = c1.radius * c1.radius * 3.14;
    double real = get_circle_area(&c1);

    ASSERT_EQUAL(expected, real);
}