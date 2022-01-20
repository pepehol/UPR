#include <stdio.h>
#include <stdlib.h>

#include "array.h"


int main()
{
    int len = 10;

    Array * a = array_new( len );

    // array_clear( a );
    // array_set( a, 2, 10 );

    // array_print( a );

    // array_save_txt( a, "array.txt" );

    // array_free( &a );

    a = array_load_txt( "array.txt" );
    array_print( a );

    array_free( &a );

    return 0;
}