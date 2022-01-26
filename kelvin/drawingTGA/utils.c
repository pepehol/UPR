#include "utils.h"

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
    int lenChar = (int) strlen(s);

    for (int i = 0; i < lenChar; i++)
    {
        // Check if it is a number.
        if ((!((ASCI_ZERO <= s[i]) && (ASCI_NINE >= s[i])) && !(s[i] == d) && 
            !(s[i] == ASCI_MINUS)) || ((s[i] == d) && (i == 0))
        )
        {
            free(arr);
            return NULL;
        }

        if ((s[i] == d) || (s[i] == ASCI_NUL))
        {
            char loader[(i - startChar) + 1];

            for (int j = 0; j < (i - startChar); j++)
            {
                loader[j] = s[startChar + j];
            }

            loader[(i - startChar)] = '\0';

            // String have multiples numbers. Return an array of max length.
            if (startArr >= number)
                break;

            arr[startArr] = atoi(loader);

            startArr++;
            startChar = i + 1;
        }
    }

    char loader[(lenChar - startChar) + 1];

    for (int j = 0; j < (lenChar - startChar); j++)
    {
        loader[j] = s[startChar + j];
    }

    loader[(lenChar - startChar)] = '\0';

    // Check the last element in the array.
    if (loader[0] == '\0')
    {
        free(arr);
        return NULL;
    }

    arr[startArr] = atoi(loader);

    if (startArr < (number - 1))
    {
        free(arr);
        return NULL;
    }
    else
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

void printIntArray(int *arr, int num)
{
    printf("Pole: ");
        for (int i = 0; i < num; i++)
            printf("%d ", arr[i]);
        printf("\n");
}