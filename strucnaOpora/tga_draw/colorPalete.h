#ifndef _COLORPALETE_H_
#define _COLORPALETE_H_

typedef unsigned char byte;

typedef struct
{
    byte blue;
    byte green;
    byte red;
    byte alpha;
} RGBA;

const RGBA RGBA_WHITE = {.red = 255, .green = 255, .blue = 255, .alpha = 255};
const RGBA RGBA_BLACK = {.red = 0, .green = 0, .blue = 0, .alpha = 255};
const RGBA RGBA_RED = {.red = 255, .green = 0, .blue = 0, .alpha = 255};
const RGBA RGBA_GREEN = {.red = 0, .green = 255, .blue = 0, .alpha = 255};
const RGBA RGBA_BLUE = {.red = 0, .green = 0, .blue = 255, .alpha = 255};
const RGBA RGBA_LIGHT_BLUE = {.red = 39, .green = 176, .blue = 245, .alpha = 153};

#endif