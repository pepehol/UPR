#include "colorPalete.h"

RGBA RGBA_WHITE = {.red = 255, .green = 255, .blue = 255, .alpha = 255};
RGBA RGBA_BLACK = {.red = 0, .green = 0, .blue = 0, .alpha = 255};
RGBA RGBA_RED = {.red = 255, .green = 0, .blue = 0, .alpha = 255};
RGBA RGBA_GREEN = {.red = 0, .green = 255, .blue = 0, .alpha = 255};
RGBA RGBA_BLUE = {.red = 0, .green = 0, .blue = 255, .alpha = 255};
RGBA RGBA_LIGHT_BLUE = {.red = 39, .green = 176, .blue = 245, .alpha = 153};
RGBA RGBA_ORANGE = { .red = 255, .green = 165, .blue = 0, .alpha = 255};


void checkRGBA(RGBA *rgba)
{
    if (
        ((rgba->red < 0) || (rgba->red > COLOR_DEPTH)) ||
        ((rgba->green < 0) || (rgba->green > COLOR_DEPTH)) ||
        ((rgba->blue < 0) || (rgba->blue > COLOR_DEPTH)) ||
        ((rgba->alpha < 0) || (rgba->alpha > COLOR_DEPTH))
    )
        callStderrExit(ERROR_RGBA, 1);
}