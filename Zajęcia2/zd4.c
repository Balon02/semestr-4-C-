#include <stdio.h>
#include <string.h>

struct Student {
    char imie[50];
    float ocenaKoncowa;
};

void sortujStudentow(struct Student *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) { //bombelki
            if (tablica[j].ocenaKoncowa < tablica[j + 1].ocenaKoncowa) { //bombelki
                struct Student temp = tablica[j]; //bombelki
                tablica[j] = tablica[j + 1]; //bombelki
                tablica[j + 1] = temp; //bombelki
            }
        }
    }
}

int main() {
    struct Student listaStudentow[] = {
        {"Szymon", 4.3},
        {"Oskar", 4.7},
        {"Pawel", 5.0},
        {"Michal", 4.2},
        {"Marcin", 3.0}
    };

    int rozmiar = sizeof(listaStudentow) / sizeof(listaStudentow[0]);

    sortujStudentow(listaStudentow, rozmiar);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%s: %.2f\n", listaStudentow[i].imie, listaStudentow[i].ocenaKoncowa);
    }

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}