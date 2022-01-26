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

void checkRectangle(Rectangle *rec, int width, int height)
{
    // Check start point.
    if (checkStartPoint(rec->x1, rec->y1, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_REC, 1);

    // Check width and height.
    if ((rec->x2 <= rec->x1) || (rec->y2 <= rec->y1) ||
        (rec->x2 > width) || (rec->y2 > height)
    )
        callStderrExit(ERROR_OFF_COORD_REC, 1);
}

void checkCircle(Circle *cir, int width, int height)
{
    // Check start point.
    if (checkStartPoint(cir->x, cir->y, width, height) == -1)
        callStderrExit(ERROR_OFF_COORD_CIR, 1);

    // Check width and height.
    if (((cir->x + cir->radius) > width) || ((cir->x - cir->radius) < 0) ||
        ((cir->y + cir->radius) > height) || ((cir->y - cir->radius) < 0)
    )
        callStderrExit(ERROR_OFF_COORD_CIR, 1);

}