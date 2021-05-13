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

FigureSet scan_file(const char* path);