#include <stdio.h>

int main() {
    int liczba = 42;

    int *wskaznik = &liczba;

    *wskaznik = 99;

    printf("bezposrednio: %d\n", liczba);

    printf("Przez wskaznik: %d\n", *wskaznik);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}