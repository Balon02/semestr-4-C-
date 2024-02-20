#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generujRuchKomputera() {
    return rand() % 3; // 0 - papier, 1 - kamień, 2 - nożyce
}

const char* nazwaRuchu(int ruch) {
    switch (ruch) {
        case 0:
            return "Papier";
        case 1:
            return "Kamien";
        case 2:
            return "Nozyce";
        default:
            return "Nieznany ruch";
    }
}

int main() {
    srand(time(NULL));

    int liczbaRund;
    printf("Podaj liczbe rund: ");
    scanf("%d", &liczbaRund);

    int wyniki[3] = {0}; // wyniki[0] - remisy, wyniki[1] - wygrane gracza, wyniki[2] - wygrane komputera

    for (int runda = 1; runda <= liczbaRund; runda++) {
        printf("\nRunda %d\n", runda);

        int ruchGracza;
        printf("Wybierz ruch (0 - Papier, 1 - Kamien, 2 - Nozyce): ");
        scanf("%d", &ruchGracza);

        // Komputer wybiera ruch
        int ruchKomputera = generujRuchKomputera();

        printf("Twoj ruch: %s\n", nazwaRuchu(ruchGracza));
        printf("Ruch komputera: %s\n", nazwaRuchu(ruchKomputera));

        // Sprawdzenie wyniku rundy
        if (ruchGracza == ruchKomputera) {
            printf("Remis!\n");
            wyniki[0]++;
        } else if ((ruchGracza == 0 && ruchKomputera == 1) ||
                   (ruchGracza == 1 && ruchKomputera == 2) ||
                   (ruchGracza == 2 && ruchKomputera == 0)) {
            printf("Wygrales!\n");
            wyniki[1]++;
        } else {
            printf("Przegrales!\n");
            wyniki[2]++;
        }
    }

    // Wyświetlenie wyników
    printf("\nWyniki po %d rundach:\n", liczbaRund);
    printf("Remisy: %d\n", wyniki[0]);
    printf("Wygrane gracza: %d\n", wyniki[1]);
    printf("Wygrane komputera: %d\n", wyniki[2]);

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}