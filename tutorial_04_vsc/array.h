#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Array_ Array;

struct Array_ {
    int * items;
    int len;
};

Array * array_new( const int len );

void array_free( Array ** self );

void array_clear( Array * self );

void array_set( Array * self, const int pos, const int value );

void array_print( Array * self );

void array_save_txt( Array * self, const char * filename );

Array * array_load_txt( const char * filename );

#endif // ARRAY_H