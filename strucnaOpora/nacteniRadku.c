#include <stdio.h>

int main() {
    char buf[80];
    // načti řádek textu ze vstupu do řetězce `buf`
    // plus ošetření
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("Nacteni dat nevyslo. Ukoncuji program\n");
        return 1;
    }
    printf("Nacteny radek = %s", buf);

    return 0;
}
