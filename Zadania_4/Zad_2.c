#include <stdio.h>

// Funkcja rekurencyjna do wyszukiwania binarnego
int binary_search_recursive(int arr[], int left, int right, int target) {
    // Jeśli lewy indeks jest większy od prawego, szukany element nie istnieje w tablicy
    if (left > right) {
        return -1;
    }

    // Ośrodkowy indeks tablicy
    int mid = left + (right - left) / 2;

    // Jeśli szukany element został znaleziony, zwróć jego indeks
    if (arr[mid] == target) {
        return mid;
    }

    // Jeśli szukany element jest mniejszy od elementu w ośrodkowym indeksie, przeskocz do lewej połowy tablicy
    if (arr[mid] > target) {
        return binary_search_recursive(arr, left, mid - 1, target);
    }

    // W przeciwnym przypadku przeskocz do prawej połowy tablicy
    return binary_search_recursive(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Wyszukiwanie binarne
    int result = binary_search_recursive(arr, 0, n - 1, target);

    // Wypisanie wyniku
    if (result != -1) {
        printf("Element %d zostal znaleziony na pozycji %d\n", target, result);
    } else {
        printf("Element %d nie zostal znaleziony w tablicy\n", target);
    }

    return 0;
}