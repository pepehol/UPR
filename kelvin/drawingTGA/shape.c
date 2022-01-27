#include "shape.h"

int checkStartPoint(int x, int y, int width, int height)
{
    // First check of the location of the starting point. x, y
    if (((x < 0) || (y < 0)) || 
        ((x >= width) || (y >= height))
    )
        return -1;

    return 0;
}

int checkEndPoint(int x1, int y1, int x2, int y2, int width, int height)
{
    if ((x2 <= x1) || (y2 <= y1) ||
        (x2 > width) || (y2 > height)
    )
        return -1;

    return 0;
}

void checkRectangle(Rectangle *rec, int width, int height)
{
    // Check start point.
    if (checkStartPoint(rec->x1, rec->y1, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_REC, 1);

    // Check width and height.
    if (checkEndPoint(rec->x1, rec->y1, rec->x2, rec->y2, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_REC, 1);
}

void checkCircle(Circle *cir, int width, int height)
{
    // Check start point.
    if (checkStartPoint(cir->x, cir->y, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_CIR, 1);

    // Check width and height.
    int x2 = cir->x + cir->radius;
    int y2 = cir->y + cir->radius;

    if (checkEndPoint(cir->x, cir->y, x2, y2, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_CIR, 1);

}

void checkTriangle(Triangle *tria, int width, int height)
{
    // Check start point.
    if (checkStartPoint(tria->x, tria->y, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_TRIA, 1);

    // Check width and height.
    int x2 = tria->x + tria->lenSide;

    // Necessary to calculate the height.
    // h = (sqrt(3) * a) / 2
    int y2 = tria->y + ((sqrt(3) * tria->lenSide) / 2);

    if (checkEndPoint(tria->x, tria->y, x2, y2, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_TRIA, 1);
}