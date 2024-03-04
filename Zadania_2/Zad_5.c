#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10

struct Contact {
    char imie[30];
    char nazwisko[30];
    char numerTelefonu[15];
};

void dodajKontakt(struct Contact *ksiazka, int *liczbaKontaktow) {
    if (*liczbaKontaktow < MAX_CONTACTS) {
        printf("Podaj imie: ");
        scanf("%s", ksiazka[*liczbaKontaktow].imie);

        printf("Podaj nazwisko: ");
        scanf("%s", ksiazka[*liczbaKontaktow].nazwisko);

        printf("Podaj numer telefonu: ");
        scanf("%s", ksiazka[*liczbaKontaktow].numerTelefonu);

        (*liczbaKontaktow)++;
        printf("Kontakt dodany!\n");
    } else {
        printf("Ksiazka adresowa jest pelna. Nie mozna dodac nowego kontaktu.\n");
    }
}

void znajdzKontakt(struct Contact *ksiazka, int liczbaKontaktow) {
    char szukaneNazwisko[30];
    printf("Podaj nazwisko do wyszukania: ");
    scanf("%s", szukaneNazwisko);

    int znaleziony = 0;

    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazka[i].nazwisko, szukaneNazwisko) == 0) {
            printf("Znaleziony kontakt:\n");
            printf("Imie: %s\n", ksiazka[i].imie);
            printf("Nazwisko: %s\n", ksiazka[i].nazwisko);
            printf("Numer telefonu: %s\n", ksiazka[i].numerTelefonu);
            znaleziony = 1;
            break;
        }
    }

    if (!znaleziony) {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

void usunKontakt(struct Contact *ksiazka, int *liczbaKontaktow) {
    char usuwaneNazwisko[30];
    printf("Podaj nazwisko do usuniecia: ");
    scanf("%s", usuwaneNazwisko);

    int indeksUsunietego = -1;

    for (int i = 0; i < *liczbaKontaktow; i++) {
        if (strcmp(ksiazka[i].nazwisko, usuwaneNazwisko) == 0) {
            indeksUsunietego = i;
            break;
        }
    }

    if (indeksUsunietego != -1) {
        for (int i = indeksUsunietego; i < (*liczbaKontaktow - 1); i++) {
            ksiazka[i] = ksiazka[i + 1];
        }

        (*liczbaKontaktow)--;
        printf("Kontakt usuniety!\n");
    } else {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

void wypiszWszystkieKontakty(struct Contact *ksiazka, int liczbaKontaktow) {
    printf("Wszystkie kontakty w ksiazce adresowej:\n");
    for (int i = 0; i < liczbaKontaktow; i++) {
        printf("%d. %s %s, Numer telefonu: %s\n", i + 1, ksiazka[i].imie, ksiazka[i].nazwisko, ksiazka[i].numerTelefonu);
    }
}

int main() {
    struct Contact ksiazkaAdresowa[MAX_CONTACTS];
    int liczbaKontaktow = 0;
    int wybor;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("0. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                dodajKontakt(ksiazkaAdresowa, &liczbaKontaktow);
                break;
            case 2:
                znajdzKontakt(ksiazkaAdresowa, liczbaKontaktow);
                break;
            case 3:
                usunKontakt(ksiazkaAdresowa, &liczbaKontaktow);
                break;
            case 4:
                wypiszWszystkieKontakty(ksiazkaAdresowa, liczbaKontaktow);
                break;
            case 0:
                printf("Program zakonczony.\n");
                break;
            default:
                printf("Nieprawidłowy wybor. Sprobuj ponownie.\n");
        }
    } while (wybor != 0);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}