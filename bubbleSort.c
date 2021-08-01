/**********************************************************
* Program BubbleSort.c, for O(n^2) sorting.
* Compile with gcc bubbleSort -o bubbleSort -g -Wall
* Note use of srand for one time seed in alternate anArray
* initialization section.
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int anArray[100], n, c, d, swap;

	/** Alternate random anArray initialization **/
	// int i, len;
	// len = sizeof(anArray) / sizeof(int);
	// srand(time(NULL));

	// for (i = 0; i < len; i++) {
	//	 anArray[i] = rand();
	// }

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (c = 0; c < n; c++)
		scanf("%d", &anArray[c]);

	for (c = 0; c < (n - 1); c++) {
		for (d = 0; d < n - c - 1; d++) {
			// For decreasing order use < .
			if (anArray[d] > anArray[d + 1]) {
				swap = anArray[d];
				anArray[d] = anArray[d + 1];
				anArray[d + 1] = swap;
			}
		}
	}

	printf("Sorted list in ascending order:\n");

	for (c = 0; c < n; c++)
		printf("%d\n", anArray[c]);

	return 0;
}