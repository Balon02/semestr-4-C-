#include <stdio.h>

int sumaWielokrotnosci(int liczba) {
    if (liczba < 0) {
        return 0;
    }
    int suma = 0;
    for (int i = 3; i < liczba; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i;
        }
    }
    return suma;
}
int main() {
    int podanaLiczba;
    printf("Podaj liczbe: ");
    scanf("%d", &podanaLiczba);
    int wynik = sumaWielokrotnosci(podanaLiczba);
    printf("Suma wielokrotnosci 3 lub 5 ponizej %d wynosi: %d\n", podanaLiczba, wynik);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}