/**********************************************************
* Merge Sort an array in c with O(n). Both dynamic and
* recursive approaches offered.
* Compile: gcc mergeSort.c -o MergeSort -g -Wall
***********************************************************/
#include<stdlib.h>
#include<stdio.h>

/* Merges two subarrays of arr[].
 * First subarray is arr[left ... middle]
 * Second subarray is arr[middle+1 ... right]. */
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    /* Create temp arrays */
    int _Left[n1], _Right[n2];

    /* Copy data to temp arrays _Left[] and _Right[] */
    for (i = 0; i < n1; i++) {
        _Left[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        _Right[j] = arr[middle + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (_Left[i] <= _Right[j]) {
            arr[k] = _Left[i];
            i++;
        }
        else {
            arr[k] = _Right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if any. */
    while (i < n1) {
        arr[k] = _Left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if any. */
    while (j < n2) {
        arr[k] = _Right[j];
        j++;
        k++;
    }
}

/* mergeSort recursive approach:
   Param arr[] - array to be sorted.
   Param left - left index of the sub-array of arr to be sorted.
   Param right - right index of the sub-array of arr to be sorted. */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (l + r) / 2, but avoids integer overflow.
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}


// Function to print an array.
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

/* Driver program to test above functions */
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}