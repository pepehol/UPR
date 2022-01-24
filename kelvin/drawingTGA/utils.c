#include "utils.h"

void utils_out_of_memory(const char *filename, const int lineno)
{
    fprintf( stderr, "Oops! Out of memory (%s:%i)\n", filename, lineno );
    exit( -1 );
}