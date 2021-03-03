#include <math.h>
#include <stdbool.h>
#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct Point{
	double x;
	double y;
}Point;

typedef struct Circle{
	Point center;
	double radius;
}Circle;

double length(Point first, Point second);

double circlePeri(Circle circle);

double circleArea(Circle circle);

double sqr(double x);

bool isCircle(Circle circle);

#endif

