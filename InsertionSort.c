/****************************************************************
* Program insertionSort.c, for O(n^2) sorting.
* Compile with gcc InsertionSort -o insertSort -g -Wall
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, temp, userInput = -1;
    int *arr;

	while (userInput < 0) {
        printf("Enter total elements to be sorted: ");
        scanf("%d", &userInput);
        if (userInput < 1) {
            printf("Sorry, input must be > 0.\n");
        }
    }

    arr = malloc(userInput * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    printf("Seperated by spaces or <Enter>,\nPlease enter %d elements: ", userInput);
    for (i = 0; i < userInput; i++) {
        scanf("%d", &arr[i]);
    }

    // Starting with 2nd element of arr[]...
    for (i = 1; i < userInput; i++) {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }

    printf("After sorting: ");
    for (i = 0; i < userInput; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // Manage memory.
    free(arr);
    arr = NULL;

    return 0;
}
