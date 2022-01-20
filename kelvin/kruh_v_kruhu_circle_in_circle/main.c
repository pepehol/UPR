/* 

Definice struktury pro kruh

Naimplementujte strukturu pro reprezentaci kruhu Circle, která reprezentuje kruh. Ten může být reprezentován polohou středu v prostoru (center) a poloměrem (radius).

Střed kruhu definujte jako další strukturu Point2, která obsahuje dva atributy x a y typu float.
Kruh v kruhu

Naimplemntujte funkci circle_contains_circle, která vrátí logickou hodnotu, zdali je kruh other obsažen v kruhu self.

bool circle_contains_circle( const Circle * self, const Circle * other );

Program načte ze standardního vstupu souřadnice polohy středu a poloměru dvou kruhů (jeden kruh na jednom řádku). Na standardní výstup program vytiskne logickou hodnotu, která je poskytnuta funkcí circle_contains_circle.

Pro získání hodnoty čísla π použijte konstantu M_PI z hlavičkového souboru math.h.

Příklad vstupu:

0.0 0.0 10.0
0.0 0.0 5.0

Příklad výstupu:

True

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    float x;
    float y;
} Point2;

typedef struct {
    Point2 center;
    float radius;
} Circle;

bool circle_contains_circle( const Circle * self, const Circle * other )
{
    if ( ( other -> center.x <= ( self -> center.x + self -> radius ) &&
        other -> center.x >= self -> center.x ) && 
        ( other -> center.y <= ( self -> center.y + self -> radius ) &&
        other -> center.y >= self -> center.y )
    )
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    float circleX = 0;
    float circleY = 0;
    float circleRadius = 0;
    scanf("%f ", &circleX);
    scanf("%f ", &circleY);
    scanf("%f ", &circleRadius);

    float circle1X = 0;
    float circle1Y = 0;
    float circle1Radius = 0;
    scanf("%f ", &circle1X);
    scanf("%f ", &circle1Y);
    scanf("%f ", &circle1Radius);

    Circle circle = { .center = { .x = circleX, .y = circleY }, .radius = circleRadius };
    Circle circle1 = { .center = { .x = circle1X, .y = circle1Y }, .radius = circle1Radius };


    printf("%s\n", circle_contains_circle( &circle, &circle1 ) ? "True" : "False"  );
}