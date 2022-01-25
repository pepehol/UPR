#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "colorPalete.h"

typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
    RGBA rgba;
} Rectangle;

typedef struct
{
    int x;
    int y;
    int radius;
    RGBA rgba;
} Circle;

typedef struct
{
    int x;
    int y;
    int lenSide;
    RGBA rgba;
} Triangle;

#endif