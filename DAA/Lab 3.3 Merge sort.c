#include <stdio.h>

void merge(int A[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int B[ub + 1]; // Create a temporary array B to store merged elements

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= ub) {
        B[k] = A[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array A
    for (i = lb; i <= ub; i++) {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int main() {
    int A[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
