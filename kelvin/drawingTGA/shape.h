#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <stdio.h>
#include <math.h>

#include "configure.h"
#include "utils.h"

typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
} Rectangle;

typedef struct
{
    int x;
    int y;
    int radius;
} Circle;

typedef struct
{
    int x;
    int y;
    int lenSide;
} Triangle;

int checkStartPoint(int x, int y, int width, int height);
int checkEndPoint(int x1, int y1, int x2, int y2, int width, int height);
void checkRectangle(Rectangle *rec, int width, int height);
void checkCircle(Circle *cir, int width, int height);
void checkTriangle(Triangle *tria, int width, int height);


#endif