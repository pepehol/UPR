#include "tga.h"

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

void TGAsetPixel(TGAImage *self, const int x, const int y, RGBA *color)
{
    int pixel = 0;
    pixel = TGA1d(x, y, TGAwidth(self));

    float alpha = (float) color->alpha / (float) COLOR_DEPTH;

    float rf = alpha * (float) color->red + (1.0 - alpha) * self->rgba[pixel].red;
    float gf = alpha * (float) color->green + (1.0 - alpha) * self->rgba[pixel].green;
    float bf = alpha * (float) color->blue + (1.0 - alpha) * self->rgba[pixel].blue;

    self->rgba[pixel].blue = (int) bf;
    self->rgba[pixel].green = (int) gf;
    self->rgba[pixel].red = (int) rf;
    self->rgba[pixel].alpha = color ->alpha;
}

void TGAdrawRect(TGAImage *tga, RGBA *rgba, Rectangle *rect)
{
    for (int y = rect->y1; y < rect->y2; y++)
    {
        for (int x = rect->x1; x < rect->x2; x++)
        {
            TGAsetPixel(tga, x, y, rgba);
        }
    }
}

TGAImage *TGAnew(const int width, const int height, RGBA *rgba)
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

    Rectangle rect = {.x1 = 0, .y1 = 0, .x2 = width, .y2 = height};

    TGAdrawRect(tga, rgba, &rect);

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

void TGAcopy(TGAImage *source, TGAImage *destination, Rectangle rect)
{
    int cnt = 0;
    for (int y = rect.y1; y < rect.y2; y++)
    {
        for (int x = rect.x1; x < rect.x2; x++)
        {
            int pixel = 0;
            pixel = TGA1d(x, y, TGAwidth(destination));

            destination->rgba[pixel].blue = source->rgba[cnt].blue;
            destination->rgba[pixel].green = source->rgba[cnt].green;
            destination->rgba[pixel].red = source->rgba[cnt].red;
            destination->rgba[pixel].alpha = source->rgba[cnt].alpha;
            cnt++;
        }
    }
}

    // int pixel = 0;
    // pixel = TGA1d(x, y, TGAwidth(self));

    // float alpha = (float) color->alpha / (float) COLOR_DEPTH;

    // float rf = alpha * (float) color->red + (1.0 - alpha) * self->rgba[pixel].red;
    // float gf = alpha * (float) color->green + (1.0 - alpha) * self->rgba[pixel].green;
    // float bf = alpha * (float) color->blue + (1.0 - alpha) * self->rgba[pixel].blue;

    // self->rgba[pixel].blue = (int) bf;
    // self->rgba[pixel].green = (int) gf;
    // self->rgba[pixel].red = (int) rf;
    // self->rgba[pixel].alpha = (int) alpha;