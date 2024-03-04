#include <stdio.h>

void podwojWartosc(float *wskaznik) {
    *wskaznik = 2 * (*wskaznik);
}

int main() {
    float liczba = 3.14;

    float *pliczba = &liczba;

    podwojWartosc(pliczba);

    printf("Nowa wartosc zmiennej: %.2f\n", liczba);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}