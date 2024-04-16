#include <stdio.h>

// Definicja funkcji do dodawania, mnożenia i odejmowania
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*funcPtr)(int, int); // Deklaracja wskaźnika do funkcji

    int a, b;
    char operation;

    printf("Enter an operation (+, -, *): ");
    scanf(" %c", &operation);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Przypisanie wskaźnika do odpowiedniej funkcji na podstawie wartości operacji
    switch (operation) {
        case '+':
            funcPtr = add;
            break;
        case '-':
            funcPtr = subtract;
            break;
        case '*':
            funcPtr = multiply;
            break;
        default:
            printf("Invalid operation!\n");
            return 1;
    }

    // Wywołanie funkcji za pomocą wskaźnika i wyświetlenie wyniku
    printf("Result: %d\n", funcPtr(a, b));

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}
