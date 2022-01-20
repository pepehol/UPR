#include <stdio.h>

void vymen(int* a, int* b) {
    int docasnaHodnota = *a;
    *a = *b;
    *b = docasnaHodnota;
}
int main() {
    int x = 5;
    int y = 10;
    printf("Po prehozeni: x=%d, y=%d\n", x, y);
    vymen(&x, &y);
    printf("Po prehozeni: x=%d, y=%d\n", x, y);
    return 0;
}