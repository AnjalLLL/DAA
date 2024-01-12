#include <stdio.h>

// Function to find minimum and maximum values in array
int minMax(int A[], int low, int high, int *min, int *max)
{
    int mid, min1, max1;
    if (low == high)
    {
        *max = *min = A[low];
    }
    else if (low == high - 1)
    {
        if (A[low] < A[high])
        {
            *max = A[high];
            *min = A[low];
        }
        else
        {
            *max = A[low];
            *min = A[high];
        }
    }
    else
    {
        mid = (low + high) / 2;
        minMax(A, low, mid, min, max);
        minMax(A, mid + 1, high, &min1, &max1);

        if (max1 > *max)
            *max = max1;
        if (min1 < *min)
            *min = min1;
    }
}

int main()
{
    int A[8] = {5, 7, 3, 4, 9, 12, 6,2};
    int min, max;
    int arraySize = 8;

    // Call the minMax function to find min and max
    minMax(A, 0, arraySize - 1, &min, &max);

    // Print the minimum and maximum values
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}

