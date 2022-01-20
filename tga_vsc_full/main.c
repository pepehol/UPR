#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int to_1d( const int row, const int col, const int cols ) {
    return col + row * cols;
}


typedef unsigned char byte;

typedef struct TGAHeader_ TGAHeader;

struct TGAHeader_ {
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
};

int tgaheader_width( const TGAHeader * self ) {
    int width = 0;

    memcpy( &width, self->width, 2 );

    return width;
}

int tgaheader_height( const TGAHeader * self ) {
    int height = 0;

    memcpy( &height, self->height, 2 );

    return height;

}

int tgaheader_channels( const TGAHeader * self ) {
    return self->depth / 8;
}
typedef struct TGA_ TGA;

struct TGA_ {
    TGAHeader header;
    byte * data;
};


TGA * tga_new( const int width, const int height, const int init_brightness ) {
    TGA * tga = (TGA *)malloc( sizeof( TGA ) );
    ALLOCTEST( tga );

    memset( &tga->header, 0, sizeof( TGAHeader ) );

    tga->header.image_type = 3;
    tga->header.depth = 8;
    tga->header.descriptor = 1 << 5;

    memcpy( &tga->header.width, &width, 2 );
    memcpy( &tga->header.height, &height, 2 );

    tga->data = (byte *)malloc( width * height * sizeof( byte ) );
    printf("Size of: %d\n", width * height);
    memset( tga->data, init_brightness, width * height * sizeof( byte ) );

    return tga;
}

void tga_free( TGA ** self ) {
    free( (*self)->data );
    (*self)->data = NULL;
    free( (*self) );
    *self = NULL;
}

int tga_width( const TGA * self ) {
    return tgaheader_width( &self->header );
}

int tga_height( const TGA * self ) {
    return tgaheader_height( &self->header );
}

int tga_channels( const TGA * self ) {
    tgaheader_channels( &self->header );
}

void tga_set_pixel( TGA * self, const int x, const int y, const byte b ) {
    printf("to_1d: %d\n", to_1d( y, x, tga_width( self ) ));
    self->data[ to_1d( y, x, tga_width( self ) ) ] = b;
}

void tga_write( const TGA * self, const char * filename ) {
    FILE * f = fopen( filename, "wb" );
    assert( f );

    fwrite( &self->header, sizeof( TGAHeader ), 1, f );

    int res = fwrite( self->data, sizeof( byte ), tga_width( self ) * tga_height( self ) * tga_channels( self ), f );
    // printf("res: %d\n", tga_width( self ) * tga_height( self ) * tga_channels( self ));
    // printf("res: %d\n", res);

    assert( res == tga_width( self ) * tga_height( self ) * tga_channels( self ) );

    fclose( f );
}

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

void draw_rect( TGA * tga, const Rect * r ) {
    for ( int y = r->y1; y < r->y2; y++ ) {
        for ( int x = r->x1; x < r->x2; x++ ) {
            tga_set_pixel( tga, x, y, 50 );
        }
    }
}

int main() {

    // FILE* file = fopen("carmack.tga", "rb");
    // assert(file);

    // TGAHeader header = {};
    // assert(fread(&header, sizeof(TGAHeader), 1, file) == 1);

    // printf("Image type: %d, pixel depth: %d\n", header.image_type, header.depth);
    // printf("Image width: %d, image height: %d\n", tgaheader_width(&header), tgaheader_height(&header));

    int width = 4;
    int height = 5;

    TGA * tga = tga_new( width, height, 200 );

    Rect r = { 1, 1, 3, 4 };

    draw_rect( tga, &r );

    tga_write( tga, "test.tga" );

    tga_free( &tga );

    return 0;
}
