#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool is_unique(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }
    return true;
}

void generate_permutations(int arr[], int left, int right) {
    if (left == right) {
        print_array(arr, right + 1);
    } else {
        for (int i = left; i <= right; i++) {
            swap(&arr[left], &arr[i]);

            if (is_unique(arr, right + 1)) {
                generate_permutations(arr, left + 1, right);
            }

            swap(&arr[left], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    generate_permutations(arr, 0, n - 1);

    return 0;
}
