#ifndef _COLORPALETE_H_
#define _COLORPALETE_H_

#include "utils.h"
#include "configure.h"

typedef unsigned char byte;

typedef struct
{
    byte blue;
    byte green;
    byte red;
    byte alpha;
} RGBA;

extern RGBA RGBA_WHITE;
extern RGBA RGBA_BLACK;
extern RGBA RGBA_RED;
extern RGBA RGBA_GREEN;
extern RGBA RGBA_BLUE;
extern RGBA RGBA_LIGHT_BLUE;
extern RGBA RGBA_ORANGE;

void checkRGBA(RGBA *rgba);

#endif