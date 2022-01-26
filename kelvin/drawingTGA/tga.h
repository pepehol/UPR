#ifndef _TGA_H_
#define _TGA_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "utils.h"
#include "shape.h"
#include "colorPalete.h"

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

int TGAwidth(const TGAImage *self);
int TGAheight(const TGAImage *self);
int TGAchannels(const TGAImage *self);

int TGA1d(const int x, const int y, const int cols);
void TGAsetPixel(TGAImage *self, const int x, const int y, RGBA *rgba);

void TGAdrawRect(TGAImage *tga, RGBA *rgba, Rectangle *rect);
void TGAdrawCircle(TGAImage *tga, RGBA *circleRGBA, Circle *circle);

TGAImage *TGAnew(const int width, const int height, RGBA *rgba);
void TGAfree(TGAImage *self);

void TGAwriteFile(const TGAImage *self, const char *fileName);

void TGAcopy(TGAImage *source, TGAImage *destination, Rectangle rect);

#endif