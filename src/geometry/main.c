#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/exception.h>
#include <libgeometry/geo.h>
int main()
{
    puts("Введите название фигуры и передайте значения по образцу:\n\n\
Object = 'circle' '(' Point ',' Number ')'\n\
| 'triangle' '(' '(' Point ',' Point ',' Point ',' Point ')' ')'\n\
| 'polygon' '(' '(' Point ',' Point ',' Point {',' Point } ')' ')'\n\n\
Пример: circle(0 0, 1.5)\n\n\
Для того, чтобы выйти введите q.\n");
    char string[64];
    do {
        gets(string);
        int name;
        checkName(string, &name);
        checkBracket(string);
        checkValue(string);
        checkEndSym(string);
        switch (name) {
        case CIRCLE:
            point o;
            double rad = 0;
            sscanf(string, "circle(%lf %lf, %lf)", &o.x, &o.y, &rad);
            checkRad(rad);
            printf("Perimetr circle: %.3f, Area circle: %.3f\n",
                   perimeterCircle(o, rad),
                   areaCircle(o, rad));

            break;
        case TRIANGLE:

            point a;
            point b;
            point c;
            point d;
            sscanf(string,
                   "triangle(%lf %lf, %lf %lf, %lf %lf, %lf %lf)",
                   &a.x,
                   &a.y,
                   &b.x,
                   &b.y,
                   &c.x,
                   &c.y,
                   &d.x,
                   &d.y);
            dontDraw(a, d);
            lineException(a, b, c);
            printf("Perimetr triangle: %f, Area triangle: %f\n",
                   perimeterTriangle(a, b, c, d),
                   areaTriangle(a, b, c, d));
            break;
        default:
            puts("Что-то пошло не так");
            break;
        }
    } while (strcmp(string, "q"));
    return 0;
}
