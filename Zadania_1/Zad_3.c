#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int silnia = 1;

    for (int i = 0; i < 10; i++) {
        silnia *= array[i];
        printf("silnia dla %d: %d\n", array[i], silnia);
    }

    char keepopen[999];
    scanf("%s", keepopen);
    return 0;
}