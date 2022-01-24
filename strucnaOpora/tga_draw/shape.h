#ifndef _SHAPE_H_
#define _SHAPE_H_

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

#define WIDTH_DIG 154
#define HEIGHT_DIG 194

Rect RECT_BG_DIG_1 = {
    .x1 = 15,
    .y1 = 15,
    .x2 = 15 + WIDTH_DIG,
    .y2 = 15 + HEIGHT_DIG
};
Rect RECT_BG_DIG_2 = {
    .x1 = 199,
    .y1 = 15,
    .x2 = 199 + WIDTH_DIG,
    .y2 = 15 + HEIGHT_DIG
};
Rect RECT_BG_DIG_3 = {
    .x1 = 15,
    .y1 = 239,
    .x2 = 15 + WIDTH_DIG,
    .y2 = 239 + HEIGHT_DIG
};
Rect RECT_BG_DIG_4 = {
    .x1 = 199,
    .y1 = 239,
    .x2 = 199 + WIDTH_DIG,
    .y2 = 239 + HEIGHT_DIG
};

#endif