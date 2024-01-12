#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}

int main() {
    int A[] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);
    bubbleSort(A, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

