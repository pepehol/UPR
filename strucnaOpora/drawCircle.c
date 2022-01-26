#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// https://stackoverflow.com/questions/20362440/best-way-to-draw-circle-in-c-using-letters

int main()
{
    int radius = 4;
    int xa = 3;
    int ya = 3;
    for (int y = 0; y <= 2 * radius; y++)
    {
        for (int x = 0; x <= 2 * radius; x++)
        {
            double distance = sqrt((double)(y - radius) * (y - radius) + (x - radius) * (x - radius));
            // printf("distance: %.2f\n", distance);
            // if (distance < radius - 0.5 && distance < radius + 0.5)
            if (distance > radius - 0.5)
            {
                printf("*");
            }
            else
                { printf(" ");}
                // printf("x: %d, y: %d\n", x, y);
        }
        printf("\n");
    }
    return 0;
}