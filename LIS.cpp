/*****************************************************************
* LIS.cpp - Recursive and Dynamic Programming implementation of
* Longest Increasing Subsequence problem.
* Compile g++ LIS.cpp -o LIS -g -Wall -std=c++0x
*************************************************************************/
#include<algorithm>
using std::reverse;
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using std::vector;


// Prototypes.
int _lis(int arr[], int n, int *max_lis_length);
int lis(int arr[], int n);
int lisDP(int arr[], int n);


int main() {
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of Recursive LIS is %d\n", lis(arr, n));
    printf("Length of DP LIS is %d\n", lisDP(arr, n));
    return 0;
}


// Wrapper function for _lis()
int lis(int arr[], int n) {
    int max_lis_length = 1; // Stores the final LIS.

    /* max_lis_length is passed as a reference below so that
       it can maintain its value between the recursive calls */
    _lis(arr, n, &max_lis_length);

    return max_lis_length;
}

// Recursive implementation for calculating LIS.
int _lis(int arr[], int n, int *max_lis_length) {
    // Base case
    if (n == 1) { return 1; }

    int current_lis_length = 1;
    for (int i = 0; i<n - 1; i++)	{
        // Recursively calculate length of  LIS ending at arr[i].
        int subproblem_lis_length = _lis(arr, i, max_lis_length);

        /* Check if appending arr[n-1] to the LIS
           ending at arr[i] gives us an LIS ending at
           arr[n-1] which is longer than the previously
           calculated LIS ending at arr[n-1] */
        if (arr[i] < arr[n - 1] && current_lis_length < (1 + subproblem_lis_length)) {
            current_lis_length = 1 + subproblem_lis_length;
        }
    }

    /* Check if currently calculated LIS ending at
       arr[n-1] is longer than the previously calculated
       LIS and update max_lis_length accordingly */ 
    if (*max_lis_length < current_lis_length) {
        *max_lis_length = current_lis_length;
    }

    return current_lis_length;
}

/* lis() returns the length of the longest increasing
 * subsequence in arr[] of size n and prints the values. O(n^2) */
int lisDP(int arr[], int n) {
    int *lis, i, j, max = 0;
    lis = (int*)malloc(sizeof(int) * n);

    // Initialize LIS values for all indexes.
    for (i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Calculate optimized LIS values bottom up.
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
         }
    }
    // Select max of all LIS values.
    for (i = 0; i < n; i++) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }
    int tmp = max;
    vector<int> indexes;
    for (i = n - 1; i >= 0; --i) {
        if (lis[i] == tmp) {
            indexes.push_back(i);
            --tmp;
        }
    }
    reverse(indexes.begin(), indexes.end());

    printf("Values of LIS = ");
    for (i = 0; i < max; i++) {
        printf("%d ", arr[indexes[i]]);
    }
    printf("\n");

    // Manage memory.
    free(lis);

    return max;
}
