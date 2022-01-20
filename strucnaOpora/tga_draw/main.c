#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "colorPalete.h"
#include "shape.h"

typedef unsigned char byte;

typedef struct
{
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} TGAHeader;

typedef struct
{
    TGAHeader header;
    RGBA *rgba;
} TGAImage;

int TGAwidth(const TGAImage *self)
{
    int width = 0;

    memcpy(&width, self->header.width, 2);

    return width;
}

int TGAheight(const TGAImage *self)
{
    int height = 0;

    memcpy(&height, self->header.height, 2);

    return height;
}

int TGAchannels(const TGAImage *self)
{
    return self->header.depth / 8;
}

int TGA1d(const int x, const int y, const int cols)
{
    return x + y * cols;
}

void TGAsetPixel(TGAImage *self, const int x, const int y, RGBA rgba)
{
    int pixel = 0;
    pixel = TGA1d(x, y, TGAwidth(self));

    self->rgba[pixel].blue = rgba.blue;
    self->rgba[pixel].green = rgba.green;
    self->rgba[pixel].red = rgba.red;
    self->rgba[pixel].alpha = rgba.alpha;
}

void TGAdrawRect(TGAImage *tga, RGBA rgba, Rect rect)
{
    for (int y = rect.y1; y < rect.y2; y++)
    {
        for (int x = rect.x1; x < rect.x2; x++)
        {
            TGAsetPixel(tga, x, y, rgba);
        }
    }
}

TGAImage *TGAnew(const int width, const int height, RGBA rgba)
{
    TGAImage *tga = (TGAImage *)malloc(sizeof(TGAImage));
    ALLOCTEST(tga);

    memset(&tga->header, 0, sizeof(TGAHeader));

    tga->header.image_type = 2;
    tga->header.depth = 32;
    tga->header.descriptor = 1 << 5;

    memcpy(&tga->header.width, &width, 2);
    memcpy(&tga->header.height, &height, 2);

    tga->rgba = (RGBA *)malloc(width * height * sizeof(RGBA));

    Rect rect = {.x1 = 0, .y1 = 0, .x2 = width, .y2 = height};

    TGAdrawRect(tga, rgba, rect);

    return tga;
}

void TGAfree(TGAImage *self)
{
    free(self->rgba);
    self->rgba = NULL;
    free(self);
    self = NULL;
}

void TGAwriteFile(const TGAImage *self, const char *fileName)
{
    FILE *f = fopen(fileName, "wb");
    assert(f);

    fwrite(&self->header, sizeof(TGAHeader), 1, f);

    int res = fwrite(self->rgba, sizeof(RGBA), TGAwidth(self) * TGAheight(self), f);
    assert(res == TGAwidth(self) * TGAheight(self));

    fclose(f);
}

void watch_prepare_bg(TGAImage *self)
{
    // Pozdadi pro cislice.
    TGAdrawRect(self, RGBA_WHITE, RECT_BG_DIG_1);
    TGAdrawRect(self, RGBA_WHITE, RECT_BG_DIG_2);
    TGAdrawRect(self, RGBA_WHITE, RECT_BG_DIG_3);
    TGAdrawRect(self, RGBA_WHITE, RECT_BG_DIG_4);

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

    TGAdrawRect(self, RGBA_BLACK, rectLineVer);
    TGAdrawRect(self, RGBA_BLACK, rectLineHor);
}

void watch_draw_time(TGAImage *self, const int hours, const int minutes)
{
    watch_prepare_bg(self);
}

int main()
{
    const int width = 368;
    const int height = 448;

    TGAImage *tga = TGAnew(width, height, RGBA_LIGHT_BLUE);
    printf("Image, width: %d, height: %d\n", TGAwidth(tga), TGAheight(tga));

    watch_draw_time(tga, 12, 4);

    TGAwriteFile(tga, "aw.tga");

    TGAfree(tga);
}