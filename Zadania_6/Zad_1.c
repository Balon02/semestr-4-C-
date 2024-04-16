#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    // Przechowuj wartość typu int
    data.i = 100;
    printf("Stored integer: %d\n", data.i);

    // Przechowuj wartość typu float
    data.f = 3.1415;
    printf("Stored float: %.2f\n", data.f);

    // Przechowuj wartość typu char
    data.c = 'A';
    printf("Stored character: %c\n", data.c);

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}