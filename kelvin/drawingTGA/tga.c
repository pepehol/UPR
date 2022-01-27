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

    float alpha = (float)color->alpha / (float)COLOR_DEPTH;

    float rf = alpha * (float)color->red + (1.0 - alpha) * self->rgba[pixel].red;
    float gf = alpha * (float)color->green + (1.0 - alpha) * self->rgba[pixel].green;
    float bf = alpha * (float)color->blue + (1.0 - alpha) * self->rgba[pixel].blue;

    self->rgba[pixel].blue = (int)bf;
    self->rgba[pixel].green = (int)gf;
    self->rgba[pixel].red = (int)rf;
    self->rgba[pixel].alpha = color->alpha;
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

void TGAdrawCircle(TGAImage *tga, RGBA *rgba, Circle *circle)
{
    // http://www.ltcconline.net/greenl/courses/154/factor/circle.htm
    // d = sqrt(x^2 + y^2)

    int radius = circle->radius;

    for (int y = 0; y <= 2 * circle->radius; y++)
    {
        for (int x = 0; x <= 2 * circle->radius; x++)
        {
            double distance = sqrt(pow((double)(y - radius), 2) +
                                   pow((double)(x - radius), 2));
            if (distance < radius - 0.5)
                TGAsetPixel(tga, x + circle->x, y + circle->y, rgba);
        }
    }
}

void TGAdrawTriangle(TGAImage *tga, RGBA *rgba, Triangle *tria)
{
    // https://en.m.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    /*
    xs,ys    x0,y0
        I----I----|
        |    *    |
        |   * *   |
        |  * * *  |
        | * * * * |
        |* * * * *|
        I---------I
        x1,y1     x2,y2
    */

    int x0 = tria->x + (tria->lenSide / 2);
    int y0 = tria->y;

    int x1 = tria->x;
    int y1 = tria->y + ((sqrt(3) * tria->lenSide) / 2);

    int x2 = tria->x + tria->lenSide;
    int y2 = tria->y + ((sqrt(3) * tria->lenSide) / 2);

    TGAsetPixel(tga, x0, y0, rgba);
    TGAsetPixel(tga, x1, y1, rgba);
    TGAsetPixel(tga, x2, y2, rgba);

    // Drawing the first half of the triangle.
    int dx = x1 - x0;
    int dy = y1 - y0;

    int xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;

    int x = x0;

    for (int y = y0; y <= y1; y++)
    {
        TGAsetPixel(tga, x, y, rgba);

        for (int i = 0; i <= x0 - x; i++)
            TGAsetPixel(tga, x + i, y, rgba);

        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2 * dx;
        }
    }

    // Drawing the second half of the triangle.
    dx = x2 - x0;
    dy = y2 - y0;

    xi = 1;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    D = (2 * dx) - dy;

    x = x0;

    for (int y = y0; y <= y2; y++)
    {
        TGAsetPixel(tga, x, y, rgba);

        // Plus one to remove the centre line.
        for (int i = 0; i <= x - x0; i++)
            TGAsetPixel(tga, x0 + i + 1, y, rgba);

        if (D > 0)
        {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2 * dx;
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
