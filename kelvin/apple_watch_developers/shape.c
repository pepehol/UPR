#include "shape.h"

// Umisteni cislic na snimku.
const Rect RECT_BG_DIG_1 = {
    .x1 = 15,
    .y1 = 15,
    .x2 = 15 + WIDTH_BG_DIG,
    .y2 = 15 + HEIGHT_BG_DIG
};

const Rect RECT_BG_DIG_2 = {
    .x1 = 199,
    .y1 = 15,
    .x2 = 199 + WIDTH_BG_DIG,
    .y2 = 15 + HEIGHT_BG_DIG
};

const Rect RECT_BG_DIG_3 = {
    .x1 = 15,
    .y1 = 239,
    .x2 = 15 + WIDTH_BG_DIG,
    .y2 = 239 + HEIGHT_BG_DIG
};

const Rect RECT_BG_DIG_4 = {
    .x1 = 199,
    .y1 = 239,
    .x2 = 199 + WIDTH_BG_DIG,
    .y2 = 239 + HEIGHT_BG_DIG
};

// Cislice.
// 0
const Rect RECT_DIG_0_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG,
};

const Rect RECT_DIG_0_2 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG,
};

const Rect RECT_DIG_0_3 =
{
    .x1 = 0,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG,
};

const Rect RECT_DIG_0_4 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG,
};

// 1
const Rect RECT_DIG_1 = 
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};

// 2
const Rect RECT_DIG_2_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_2_2 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_2_3 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_2_4 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_2_5 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};

// 3
const Rect RECT_DIG_3_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_3_2 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_3_3 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_3_4 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_3_5 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};

// 4
const Rect RECT_DIG_4_1 = 
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_4_2 = 
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG - WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
};
const Rect RECT_DIG_4_3 = 
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};

// 5
const Rect RECT_DIG_5_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_5_2 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_5_3 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_5_4 =
{
    .x1 = 0,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_5_5 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};

// 6
const Rect RECT_DIG_6_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_6_2 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_6_3 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_6_4 =
{
    .x1 = 0,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_6_5 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};
const Rect RECT_DIG_6_6 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};

// 7
const Rect RECT_DIG_7_1 = 
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_7_2 = 
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG - WIDTH_DIG,
    .y2 = WIDTH_DIG
};

// 8
const Rect RECT_DIG_8_1 =
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_8_2 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_8_3 =
{
    .x1 = 0,
    .y1 = HEIGHT_BG_DIG - 30,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_8_4 =
{
    .x1 = 0,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};
const Rect RECT_DIG_8_5 =
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};
const Rect RECT_DIG_8_6 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG - WIDTH_DIG
};
const Rect RECT_DIG_8_7 =
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_BG_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};

// 9
const Rect RECT_DIG_9_1 = 
{
    .x1 = WIDTH_BG_DIG - WIDTH_DIG,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG,
    .y2 = HEIGHT_BG_DIG
};
const Rect RECT_DIG_9_2 = 
{
    .x1 = 0,
    .y1 = 0,
    .x2 = WIDTH_BG_DIG - WIDTH_DIG,
    .y2 = WIDTH_DIG
};
const Rect RECT_DIG_9_3 = 
{
    .x1 = 0,
    .y1 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2),
    .x2 = WIDTH_BG_DIG - WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) + (WIDTH_DIG_1 / 2),
};
const Rect RECT_DIG_9_4 = 
{
    .x1 = 0,
    .y1 = WIDTH_DIG,
    .x2 = WIDTH_DIG,
    .y2 = (HEIGHT_BG_DIG / 2) - (WIDTH_DIG_1 / 2)
};