#include "array.h"

Array * array_new( const int len ) {
    Array * arr = NULL;
    arr = (Array *)malloc( sizeof(Array) );

    arr->items = (int *)malloc( len * sizeof( int ) );
    arr->len = len;

    return arr;
}

void array_free( Array ** self ) {
    free( (*self)->items );
    (*self)->items = NULL;
    free( *self );
    *self = NULL;
}

void array_clear( Array * self ) {
    for ( int i = 0; i < self->len; i++ ) {
        self->items[ i ] = 0;
    }
}

void array_set( Array * self, const int pos, const int value ) {
    if ( pos >= 0 && pos < self->len ) {
        self->items[ pos ] = value;
    } else {
         fprintf( stderr, "Index out of range!" );
    }
}

void array_print( Array * self ) {
    for ( int i = 0; i < self->len; i++ ) {
        printf( "%d ", self->items[ i ] );
    }
    printf( "\n" );
}

void array_save_txt( Array * self, const char * filename ) {
    FILE * f = NULL;

    f = fopen( filename, "wt" );
    if ( !f ) {
        fprintf( stderr, "Unable to open file!\n" );
        exit( -15 );
    }

    fprintf( f, "%d ", self->len );
    for ( int i = 0; i < self->len; i++ ) {
        fprintf( f, "%d ", self->items[ i ] );
    }

    fclose( f );
}

Array * array_load_txt( const char * filename ) {
    FILE * f = NULL;

    f = fopen( filename, "rt" );
    if ( !f ) {
        fprintf( stderr, "Unable to open file!\n" );
        exit( -15 );
    }

    int len = 0;

    fscanf( f, "%d", &len );

    Array * self = array_new( len );

    for ( int i = 0; i < self->len; i++ ) {
        fscanf( f, "%d", &self->items[ i ] );
    }

    fclose( f );

    return self;
}