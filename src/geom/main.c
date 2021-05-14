#include <libgeom/geometry.h>
#include <stdio.h>

int main(int argc, const char** argv)
{
    if (argc != 2) {
        printf("Enter file path\n");
        return 1;
    }
    FigureSet set = scan_file(argv[1]);
    printf("%zu\n", set.count);
    return 0;
}