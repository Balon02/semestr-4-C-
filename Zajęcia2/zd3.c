#include <stdio.h>

struct Point {
    float x;
    float y;
};

void zmienWspolrzedne(struct Point *punkt, float nowaX, float nowaY) {
    punkt->x = nowaX;
    punkt->y = nowaY;
}

struct Rectangle {
    struct Point *lewyGorny;
    struct Point *prawyDolny;
};

void obliczPoleObjetoscObwod(struct Rectangle *prostokat) {
    float dlugosc = prostokat->prawyDolny->x - prostokat->lewyGorny->x;
    float szerokosc = prostokat->prawyDolny->y - prostokat->lewyGorny->y;

    float pole = dlugosc * szerokosc;
    float obwod = 2 * dlugosc + 2 * szerokosc;

    printf("Pole prostokata: %.2f\n", pole);
    printf("Obwod prostokata: %.2f\n", obwod);
}

int main() {
    struct Point punkt1 = {1.0, 2.0};
    struct Point *ppunkt1 = &punkt1;
    zmienWspolrzedne(ppunkt1, 3.0, 4.0);

    printf("Nowe wspolrzedne punktu: (%.2f, %.2f)\n", punkt1.x, punkt1.y);

    struct Point pr1 = {0.0, 0.0};
    struct Point *ppr1 = &pr1;    
    struct Point pr2 = {2.0, 2.0};
    struct Point *ppr2 = &pr2;


    struct Rectangle prostokat1 = {ppr1, ppr2};

    obliczPoleObjetoscObwod(&prostokat1);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}