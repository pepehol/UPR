#include "utils.h"
#include "string.h"

void utils_out_of_memory(const char *filename, const int lineno)
{
    fprintf( stderr, "Oops! Out of memory (%s:%i)\n", filename, lineno );
    exit( -1 );
}

int * transArrCharToInt(char *s, char d, const int number)
{
    int *arr = malloc(number * sizeof(int *));
    ALLOCTEST(arr);
    memset(arr, 0, number * sizeof(int));

    int startChar = 0;
    int startArr = 0;
    for (int i = 0; i <= (int) strlen(s); i++)
    {
        if ((s[i] == d) || (s[i] == '\0'))
        {
            char loader[(i - startChar) + 1];

            for (int j = 0; j < (i - startChar); j++)
            {
                loader[j] = s[startChar + j];
            }

            loader[(i - startChar)] = '\0';

            arr[startArr] = atoi(loader);

            startArr++;
            startChar = i + 1;
        }
    }

    return arr;
}

void callStderrExit(char *s, int t)
{
    fprintf(stderr, "%s", s);
    switch (t)
    {
    case 1:
        exit(1);
    default:
        exit(1);
    }
}