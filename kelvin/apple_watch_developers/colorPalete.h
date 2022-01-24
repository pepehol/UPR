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

extern RGBA RGBA_WHITE;
extern RGBA RGBA_BLACK;
extern RGBA RGBA_RED;
extern RGBA RGBA_GREEN;
extern RGBA RGBA_BLUE;
extern RGBA RGBA_LIGHT_BLUE;
extern RGBA RGBA_ORANGE;

#endif