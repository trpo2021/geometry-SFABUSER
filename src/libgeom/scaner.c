#include <inttypes.h>
#include <libgeom/geometry.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_circle(Circle* circle)
{
    if (circle->radius <= 0)
        return false;
    return true;
}

size_t skip_spaces(const char* data, size_t start_index)
{
    while (data[start_index] == ' ' || data[start_index] == '\t') {
        ++start_index;
    }
    return start_index;
}

static void print_error(const char* data, size_t index)
{
    printf("%s\n", data);
    printf("%*c", (int32_t)index, ' ');
    if (index == strlen(data))
        printf("^ Unexpected end of line\n");
    else
        printf("^ Unexpected token\n");
}

static double str_to_double(const char* data, size_t* pos)
{
    size_t start = *pos;
    bool has_dot = false;

    while (data[*pos] >= '0' && data[*pos] <= '9') {
        ++*pos;
        if (data[*pos] == '.' && !has_dot) {
            has_dot = true;
            ++*pos;
        }
    }

    char buf[128] = {0};
    memcpy(buf, &data[start], *pos - start);
    double res = strtod(buf, NULL);
    return res;
}

static Circle* parse_circle(const char* data)
{
    size_t start = skip_spaces(data, 0);

    const char* word = strstr(data, "circle");
    if (word != (data + start)) {
        print_error(data, start);
        return NULL;
    }

    start += strlen("circle");
    start = skip_spaces(data, start);
    if (data[start] != '(') {
        print_error(data, start);
        return NULL;
    }
    ++start;

    Point p = {0};
    int8_t sign = 1;

    start = skip_spaces(data, start);
    if (data[start] == '-') {
        ++start;
        sign *= -1;
    }

    if (data[start] < '0' || data[start] > '9') {
        print_error(data, start);
        return NULL;
    }
    p.x = str_to_double(data, &start) * sign;
    sign = 1;

    start = skip_spaces(data, start);
    if (data[start] == '-') {
        ++start;
        sign *= -1;
    }
    if (data[start] < '0' || data[start] > '9') {
        print_error(data, start);
        return NULL;
    }
    p.y = str_to_double(data, &start) * sign;
    sign = 1;

    if (data[start] != ',') {
        print_error(data, start);
        return NULL;
    }

    ++start;
    start = skip_spaces(data, start);
    if (data[start] == '-') {
        ++start;
        sign *= -1;
    }
    if (data[start] < '0' || data[start] > '9') {
        print_error(data, start);
        return NULL;
    }
    double radius = str_to_double(data, &start) * sign;

    if (data[start] != ')') {
        print_error(data, start);
        return NULL;
    }

    Circle* circle = malloc(sizeof(Circle));
    circle->radius = radius;
    circle->coords = p;

    return circle;
}

static void add_to_set(FigureSet* set, Circle* cir)
{
    if (set->count >= set->cap) {
        set->array = realloc(set->array, ((set->cap + 1) * 2));
        set->cap = (set->cap + 1) * 2;
    }
    set->array[set->count++] = cir;
}

FigureSet scan_file(const char* path)
{
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("File read error\n");
        exit(EXIT_FAILURE);
    }

    char* buf = NULL;
    size_t size = 0;
    int64_t read;

    FigureSet set = {.cap = 10, .array = malloc(10), .count = 0};

    while ((read = getline(&buf, &size, fp)) != -1) {
        if (strlen(buf) > strlen("circle(0 0,0)")) {
            Circle* cir = parse_circle(buf);
            if (cir && is_circle(cir))
                add_to_set(&set, cir);
            else
                printf("Wrong circle: %s\n", buf);
        } else {
            printf("Wrong signature, use syntax: circle(number number, "
                   "number)\n");
        }
    }

    fclose(fp);

    return set;
}