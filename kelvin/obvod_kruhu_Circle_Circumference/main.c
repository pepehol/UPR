#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point2;


typedef struct {
    Point2 center;
    float radius;
} Circle;

float circle_perimeter( const Circle * self )
{
    return 2 * M_PI * self->radius;
}

int main()
{
    float inptX = 0;
    scanf("%f ", &inptX);

    float inptY = 0;
    scanf("%f ", &inptY);

    float inptRadius = 0;
    scanf("%f ", &inptRadius);

    Circle circle = {.center = {.x = inptX, .y = inptY}, .radius = inptRadius};
    float result = circle_perimeter(&circle);

    printf("%.2f\n", result);

    return 0;
}