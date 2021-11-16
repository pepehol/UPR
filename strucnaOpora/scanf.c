#include <stdio.h>

int main()
{
    int cislo;
    scanf("%d", &cislo);

    char radek[80];
    fgets(radek, sizeof(radek), stdin);

    printf("Nactenu retezec = %s, nactene cislo = %d", radek, cislo);
}