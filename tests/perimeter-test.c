#include <ctest.h>
#include <libgeom/geometry.h>

CTEST(circle_perimeter, get_perimeter)
{
    Circle c1 = {.coords.x = 0, .coords.y = 0, .radius = 3};

    double expected = 2 * c1.radius * 3.14;
    double real = get_circle_perimeter(&c1);

    ASSERT_EQUAL(expected, real);
}