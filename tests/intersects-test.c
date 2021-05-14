#include <ctest.h>
#include <libgeom/geometry.h>

CTEST(intersection, circle_circle_success)
{
    Circle c1 = {.coords.x = 0, .coords.y = 0, .radius = 3};
    Circle c2 = {.coords.x = 2, .coords.y = 1, .radius = 2};

    int real = is_intersects(&c1, &c2);

    ASSERT_TRUE(real);
}

CTEST(intersection, circle_circle_fail)
{
    Circle c1 = {.coords.x = 123, .coords.y = 321, .radius = 3};
    Circle c2 = {.coords.x = 0, .coords.y = 0, .radius = 2};

    int real = is_intersects(&c1, &c2);

    ASSERT_FALSE(real);
}