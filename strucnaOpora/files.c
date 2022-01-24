#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
    FILE *f = fopen("file.txt", "rt");
    if (!f)
    {
        fprintf(stderr, "%s%s%s", "Vstupni soubor \"", "file.txt", 
            "\" neexistuje.\n");

        exit(1);
    }

    fseek(f, 0, SEEK_END);

    int fSize = ftell(f);

    fseek(f, 0, SEEK_SET);

    char *pString = NULL;

    pString = (char *) malloc(fSize + 1);

    assert(pString);

    fread(pString, fSize, 1, f);

    for (int i = 0; i < fSize; i++)
    {
        printf("%d ", pString[i]);
    }
    printf("\n");
    for (int i = 0; i < fSize; i++)
    {
        printf("%c ", pString[i]);
    }
    printf("\n");

    printf("KONEC: %d\n", pString[fSize]);

    pString[fSize] = 0;

    free(pString);

    fclose(f);
}