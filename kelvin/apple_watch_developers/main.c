#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "colorPalete.h"
#include "shape.h"
#include "tga.h"

void draw_zero(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_0_1);
    TGAdrawRect(self, rgba, RECT_DIG_0_2);
    TGAdrawRect(self, rgba, RECT_DIG_0_3);
    TGAdrawRect(self, rgba, RECT_DIG_0_4);
}

void draw_one(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_1);
}

void draw_two(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_2_1);
    TGAdrawRect(self, rgba, RECT_DIG_2_2);
    TGAdrawRect(self, rgba, RECT_DIG_2_3);
    TGAdrawRect(self, rgba, RECT_DIG_2_4);
    TGAdrawRect(self, rgba, RECT_DIG_2_5);
}

void draw_three(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_3_1);
    TGAdrawRect(self, rgba, RECT_DIG_3_2);
    TGAdrawRect(self, rgba, RECT_DIG_3_3);
    TGAdrawRect(self, rgba, RECT_DIG_3_4);
    TGAdrawRect(self, rgba, RECT_DIG_3_5);
}

void draw_four(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_4_1);
    TGAdrawRect(self, rgba, RECT_DIG_4_2);
    TGAdrawRect(self, rgba, RECT_DIG_4_3);
}

void draw_five(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_5_1);
    TGAdrawRect(self, rgba, RECT_DIG_5_2);
    TGAdrawRect(self, rgba, RECT_DIG_5_3);
    TGAdrawRect(self, rgba, RECT_DIG_5_4);
    TGAdrawRect(self, rgba, RECT_DIG_5_5);
}

void draw_six(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_6_1);
    TGAdrawRect(self, rgba, RECT_DIG_6_2);
    TGAdrawRect(self, rgba, RECT_DIG_6_3);
    TGAdrawRect(self, rgba, RECT_DIG_6_4);
    TGAdrawRect(self, rgba, RECT_DIG_6_5);
    TGAdrawRect(self, rgba, RECT_DIG_6_6);

}

void draw_seven(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_7_1);
    TGAdrawRect(self, rgba, RECT_DIG_7_2);
}

void draw_eight(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_8_1);
    TGAdrawRect(self, rgba, RECT_DIG_8_2);
    TGAdrawRect(self, rgba, RECT_DIG_8_3);
    TGAdrawRect(self, rgba, RECT_DIG_8_4);
    TGAdrawRect(self, rgba, RECT_DIG_8_5);
    TGAdrawRect(self, rgba, RECT_DIG_8_6);
    TGAdrawRect(self, rgba, RECT_DIG_8_7);
}

void draw_nine(TGAImage *self, RGBA *rgba)
{
    TGAdrawRect(self, rgba, RECT_DIG_9_1);
    TGAdrawRect(self, rgba, RECT_DIG_9_2);
    TGAdrawRect(self, rgba, RECT_DIG_9_3);
    TGAdrawRect(self, rgba, RECT_DIG_9_4);
}

void watch_prepare_bg(TGAImage *self)
{
    // Ohraniceni horizontalni, vertikalni a ramecek.
    Rect rectLineVer = {
        .x1 = (TGAwidth(self) / 2) - 1,
        .y1 = 0,
        .x2 = (TGAwidth(self) / 2) + 1,
        .y2 = TGAheight(self)
    };
    Rect rectLineHor = {
        .x1 = 0,
        .y1 = (TGAheight(self) / 2) - 1,
        .x2 = TGAwidth(self),
        .y2 = (TGAheight(self) / 2) + 1
    };


    TGAdrawRect(self, &RGBA_BLACK, rectLineVer);
    TGAdrawRect(self, &RGBA_BLACK, rectLineHor);
}

void watch_draw_dig(TGAImage *self, int position, int value, RGBA *fg, RGBA *bg)
{
    TGAImage *tgaNumber = TGAnew(WIDTH_BG_DIG, HEIGHT_BG_DIG, bg);

    switch (value)
    {
    case 0:
        draw_zero(tgaNumber, fg);
        break;
    case 1:
        draw_one(tgaNumber, fg);
        break;
    case 2:
        draw_two(tgaNumber, fg);
        break;
    case 3:
        draw_three(tgaNumber, fg);
        break;
    case 4:
        draw_four(tgaNumber, fg);
        break;
    case 5:
        draw_five(tgaNumber, fg);
        break;
    case 6:
        draw_six(tgaNumber, fg);
        break;
    case 7:
        draw_seven(tgaNumber, fg);
        break;
    case 8:
        draw_eight(tgaNumber, fg);
        break;
    case 9:
        draw_nine(tgaNumber, fg);
        break;
    default:
        break;
    }

    if(position == 1)
        TGAcopy(tgaNumber, self, RECT_BG_DIG_1);
    else if(position == 2)
        TGAcopy(tgaNumber, self, RECT_BG_DIG_2);
    else if(position == 3)
        TGAcopy(tgaNumber, self, RECT_BG_DIG_3);
    else if(position == 4)
        TGAcopy(tgaNumber, self, RECT_BG_DIG_4);

    TGAfree(tgaNumber);
}

void watch_prepare_time(
    TGAImage* self,
    const int hours,
    const int minutes,
    RGBA* fg_color,
    RGBA* bg_color
)
{
    watch_prepare_bg(self);

    // Kontrola prekroceni casu.
    assert((hours >= 0) && (hours <= 24));
    assert((minutes >= 0) && (minutes <= 59));

    int ones = hours % 10;
    int tens = (hours / 10) % 10;

    watch_draw_dig(self, 1, tens, fg_color, bg_color);
    watch_draw_dig(self, 2, ones, fg_color, bg_color);
    printf("Zapis cas: %d%d:", tens, ones);

    ones = minutes % 10;
    tens = (minutes / 10) % 10;

    watch_draw_dig(self, 3, tens, fg_color, bg_color);
    watch_draw_dig(self, 4, ones, fg_color, bg_color);

    printf("%d%d\n", tens, ones);
}

void watch_draw_time(TGAImage *self, const int hours, const int minutes)
{
    watch_prepare_time(self, hours, minutes, &RGBA_ORANGE, &RGBA_WHITE);
}

void watch_draw_time_color(
    TGAImage* self,
    const int hours,
    const int minutes,
    RGBA* fg_color,
    RGBA* bg_color
)
{
    watch_prepare_time(self, hours, minutes, fg_color, bg_color);
}

int main(int argc, char *argv[])
{
    // Kontrola parametru.
    if(!(argc == 3))
    {
        printf("Zadany spatny pocet parametru.\n");
        return -1;
    }

    // Kontrola atoi, retezec vraci nulu.
    if(((argv[1][0] < 48) || (argv[1][0] > 57)) || ((argv[2][0] < 48) || (argv[2][0] > 57)))
    {
        printf("Hups je tam retezec znaku.\n");
        return -1;
    }

    const int width = 368;
    const int height = 448;

    int hours = atoi(argv[1]);
    int minutes = atoi(argv[2]);

    TGAImage *tga = TGAnew(width, height, &RGBA_LIGHT_BLUE);
    printf("Image, width: %d, height: %d\n", TGAwidth(tga), TGAheight(tga));

    // watch_draw_time(tga, 8, 12);
    watch_draw_time_color(tga, hours, minutes, &RGBA_ORANGE, &RGBA_WHITE);

    TGAwriteFile(tga, "aw.tga");

    TGAfree(tga);
}