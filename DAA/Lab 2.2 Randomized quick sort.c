#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            exchange(&A[i], &A[j]);
        }
    }

    exchange(&A[i + 1], &A[r]);
    return i + 1;
}

int randomizedPartition(int A[], int p, int r) {
    srand(time(0));
    int i = p + rand() % (r - p + 1);
    exchange(&A[r], &A[i]);
    return partition(A, p, r);
}

void randomizedQuickSort(int A[], int p, int r) {
    if (p < r) {
        int q = randomizedPartition(A, p, r);
        randomizedQuickSort(A, p, q - 1);
        randomizedQuickSort(A, q + 1, r);
    }
}

int main() {
    int A[] = {2, 5, 4, 1, 9, 3};
    int p = 0;
    int r = 5;

    randomizedQuickSort(A, p, r);

    printf("Sorted Array: ");
    for (int i = 0; i <= r; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
