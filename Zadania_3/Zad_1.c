#include <stdio.h>
#include <stdlib.h>

void print_pascal_triangle(int n) {
    // Dynamiczne przydzielenie pamięci dla tablicy dwuwymiarowej
    int **pascal_triangle = (int **)malloc(n * sizeof(int *));
    //Przydział dla poszczególnych wierszy
    for (int i = 0; i < n; i++) {
        pascal_triangle[i] = (int *)malloc((i + 1) * sizeof(int));
    }

    // Wypełnianie tablicy wartościami trójkąta Pascala
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            // Pierwszy i ostatni element w każdym wierszu są zawsze 1
            if (j == 0 || j == i) {
                pascal_triangle[i][j] = 1;
            } else {
                // Wartość w tablicy jest sumą wartości powyżej i po lewej stronie
                pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
            }
        }
    }

    // Wyświetlanie tablicy w terminalu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", pascal_triangle[i][j]);
        }
        printf("\n");
    }

    // Zwolnienie przydzielonej pamięci
    for (int i = 0; i < n; i++) {
        free(pascal_triangle[i]);
    }
    free(pascal_triangle);
}

int main() {
    int n;
    scanf("%d",&n);
    print_pascal_triangle(n);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}