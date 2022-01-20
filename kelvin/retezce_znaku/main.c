#include <stdio.h>

#define UPPER_START 65
#define UPPER_END 90
#define LOW_START 97
#define LOW_END 122

int main()
{
    char buf[100] = {0};

    if (fgets(buf, sizeof(buf), stdin) == NULL)
    {
        printf("Nacteni dat nevyslo. Ukoncuji program\n");
        return 1;
    }

    int x = 0;
    while (buf[x] != 0)
    {
        if ((buf[x] <= UPPER_END && buf[x] >= UPPER_START) ||
                (buf[x] <= LOW_END && buf[x] >= LOW_START))
            printf("%c", buf[x]);
        x++;
    }

    // printf("\n");

    return 0;
}