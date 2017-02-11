#include <iostream>
using std::cout;
#include <algorithm>
using std::count;

// Prototype.
int majority(int*, int);

int main() {
	int arr[] = { 7,5,7,4,7,7,7,8,7,7,5,5,7,5,7,5,5,7,7,8 };
	int numElem = sizeof(arr) / sizeof(*arr);
	int result = majority(arr, numElem);
	if (result == -1) {
		cout << "No majority element exists!\n";
	}
	else {
		cout << "Majority element is: " << result << "\n";
	}
	return 0;
}

/*******************************************************************
* Function majority()
* Input:
*	*arr		The array to be checked for majority elements
*	numElem	The number of elements in the array.
* Output:
*	return	An int that represents the majority element or -1
* TODO: What if the majority element is -1?
*******************************************************************/
int majority(int* arr, int numElem) {
	// Base case.
	if (numElem == 1) {
		return arr[0];
	}
	// Divide arr[].
	int mid = numElem / 2;

	// Recursive calls to Left and Right side.
	int majorityLeft = majority(arr, mid);
	int majorityRight = majority(arr + mid, numElem - mid);

	// Test for equality.
	if (majorityLeft == majorityRight) {
		return majorityLeft;
	}
	// Check for count(start, stop, needle) > 1/2 of elements.
	if (count(arr, arr + numElem, majorityLeft) > numElem / 2) {
		return majorityLeft;
	}
	// Check for count(start, stop, needle) > 1/2 of elements.	
	if (count(arr, arr + numElem, majorityRight) > numElem / 2) {
		return majorityRight;
	}
	return -1; // No majority found!
}
