#include <stdio.h>

int main() {
    // Create an array of 10 integers and initialize it with values 0 to 9
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Use a pointer to print each element of the array using pointer arithmetic
    int *ptr = array; // assign the address of the first element of the array to the pointer

    // Iterate through the array using pointer arithmetic and print each element
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d, *ptr = %d, ptr = %p\n", i, array[i], *ptr, ptr);
        ptr++; // move the pointer to the next element
    }

    char keepopen[999];
    scanf("%s", keepopen);

    return 0;
}
