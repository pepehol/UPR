#include "shape.h"

void checkRectangle(Rectangle *rec, int width, int height)
{
    // First check of the location of the starting point. x, y
    if (((rec->x1 < 0) || (rec->y1 < 0)) || 
        ((rec->x1 >= width) || (rec->y1 >= height))
    )
        callStderrExit(ERROR_OFF_COORDINATE, 1);

    // Check width and height.
    if ((rec->x2 <= rec->x1) || (rec->y2 <= rec->y1) ||
        (rec->x2 > width) || (rec->y2 > height)
    )
        callStderrExit(ERROR_OFF_COORDINATE, 1);
}