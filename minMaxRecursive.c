/******************************************************************************
* minMaxRecursive.c finds and prints the min and max values of an int array
* using recursion.  Runs in O(3N/2-2) = O(lgn) based on comparisons.
* Compile with gcc minMaxRecursive.c -o minMaxRecurse -g -Wall 
* Adapted from http://stackoverflow.com/questions/13544476/ 
*****************************************************************************/
#include <stdio.h>

// Change this #define to 0 to suppress recursion trace printing.
#define PRINTCASE 1

// Prototype.
void minMax(int*, int, int, int*, int*);

int main() {
    int arr[] = { 14, 6, 8, 43, 0, -1, 19, 1112, 709, 2 };
    int size = sizeof(arr) / sizeof(int) - 1;
    int min, max;
    minMax(arr, 0, size, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);
    return 0;
}

/*******************************************************
* Function minMax()
* int* arr  Pointer to arr[]
* int* min  Pointer to min val (passed by reference)
* int* max  Pointer to max val (passed by reference)
* int i     0
* int size  Index calculated # elements in arr[] - 1.
*******************************************************/
void minMax(int* arr, int i, int size, int* min, int* max) {
    int lmin, lmax, mid, rmin, rmax;
    // Base case, one element.
    if (i == size) {
        if (PRINTCASE) { printf("In Base case\n"); }
        *min = arr[i];
        *max = arr[size];
    }
    // Base case, two elements.
    else if (size == i + 1) {
        if (PRINTCASE) { printf("In Base case 2\n"); }
        if (arr[i] > arr[size]) {
            *min = arr[size];
            *max = arr[i];
        }
        else {
            *min = arr[i];
            *max = arr[size];
        }
    }
    // Recursive case.
    else {
        if (PRINTCASE) { printf("In Recursive Case\n"); }
        mid = (i + size) / 2;
        minMax(arr, i, mid, &lmin, &lmax);
        minMax(arr, mid + 1, size, &rmin, &rmax);
        *min = (lmin > rmin) ? rmin : lmin;
        *max = (lmax > rmax) ? lmax : rmax;
    }
}
