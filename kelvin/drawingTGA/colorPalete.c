#include "colorPalete.h"

RGBA RGBA_WHITE = {.red = 255, .green = 255, .blue = 255, .alpha = 255};
RGBA RGBA_BLACK = {.red = 0, .green = 0, .blue = 0, .alpha = 255};
RGBA RGBA_RED = {.red = 255, .green = 0, .blue = 0, .alpha = 255};
RGBA RGBA_GREEN = {.red = 0, .green = 255, .blue = 0, .alpha = 255};
RGBA RGBA_BLUE = {.red = 0, .green = 0, .blue = 255, .alpha = 255};
RGBA RGBA_LIGHT_BLUE = {.red = 39, .green = 176, .blue = 245, .alpha = 153};
RGBA RGBA_ORANGE = { .red = 255, .green = 165, .blue = 0, .alpha = 255};


int checkRGBA(int *arr, int num)
{
    for (int i = num - 4; i < num; i++)
        if ((arr[i] < 0) || (arr[i] > COLOR_DEPTH))
            return -1;

    return 0;
}