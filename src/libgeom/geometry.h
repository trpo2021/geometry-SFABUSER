#pragma once

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point coords;
    double radius;
} Circle;

typedef struct {
    long cap;
    long count;
    Circle** array;
} FigureSet;

double get_circle_perimeter(Circle* circle);

double get_circle_area(Circle* circle);

FigureSet scan_file(const char* path);