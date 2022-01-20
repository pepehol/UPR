#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
Naimplementujte strukturu pro reprezentaci kruhu Circle, která reprezentuje kruh. Ten může být reprezentován polohou středu v prostoru (center) a poloměrem (radius).

    Střed kruhu nejprve definujte jako dva floaty pro definici polohy x a y.
    Pak definujte střed kruhu jako další strukturu Point2, která obsahuje dva atributy x a y typu float.

*/
typedef struct {
    float x;
    float y;
} Point2;

typedef struct {
    Point2 center;
    float radius;
} Circle;

/* Funkce vrátí obvod kruhu podle dobře známého vzorce. */
float circle_circumference( const Circle * self )
{
    return 2 * M_PI * self -> radius;
}

/* Funkce vrátí obsah kruhu podle dobře známého vzorce. */
float circle_area( const Circle * self)
{
    return M_PI * sqrt(self->radius);
}

/* Funkce vrátí průměr kruhu (ve struktuře je delkarován pouze poloměr kruhu). */
float circle_diameter( const Circle * self)
{
    return 2 * self->radius;
}

/* Funkce vrátí logickou hodnotu, zdali je kruh other obsažen v kruhu self. */
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
/*     float floatX = 0;
    float floatY = 0;
    float floatRadius = 0;

    printf( "Zadej x souradnici kruhu: \n" );
    scanf( "%f", &floatX );
    printf( "Zadej y souradnici kruhu: \n" );
    scanf( "%f", &floatY );
    printf( "Zadej polomer kruhu: \n" );
    scanf( "%f", &floatRadius );

    Circle circle = { .center = { .x = floatX, .y = floatY }, .radius = floatRadius };
    printf( "Obvod kruhu: %.2f\n", circle_circumference( &circle ) );
    printf( "Obsah kruhu: %.2f\n", circle_area( &circle ) );
    printf( "Prumer kruhu: %.2f\n", circle_diameter( &circle ) ); */

    Circle circle1 = { .center = { .x = 0.0, .y = 0.0 }, .radius = 2.0 };
    Circle circle2 = { .center = { .x = 1.9, .y = 2.0 }, .radius = 2.0 };

    printf("Rovnaji se kruhy? %s\n", circle_contains_circle( &circle1, &circle2 ) ? "ANO" : "NE"  );
}