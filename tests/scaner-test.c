#include <ctest.h>
#include <libgeom/geometry.h>

CTEST(scaner, scan)
{
    FigureSet set = scan_file("data/test.txt");
    ASSERT_EQUAL(4, set.count);
}