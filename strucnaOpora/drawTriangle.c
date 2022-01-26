#include <stdio.h>

int main()
{
    int lenSide = 8;
    int top = lenSide / 2;
    int leftRight = top;

    for (int i = 0; i < lenSide; i++)
    {
        for (int j = 0; j < lenSide; j++)
        {
            if (i > 0)
            {
                if (j == leftRight + i)
                {
                    printf("x");
                    continue;
                }
                if (j == leftRight - i)
                {
                    printf("x");
                    continue;
                }
            }
            else
            {
                if (j == top)
                {
                    printf("x");
                    continue;
                }
            }
            printf(" ");
        }
        printf("\n");
    }
    for (int k = 0; k < lenSide + 1; k++)
        printf("x");
    printf("\n");

    return 0;
}