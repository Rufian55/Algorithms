/*************************************************************************
* quarternarySearch.cpp searchs a sorted int array in O(log[base4](n))
* Adapted from an article by Taranjit Khokhar
* September 2016 | IJIRT | Volume 3 Issue 4 | ISSN: 2349-6002
* IJIRT 143908 INTERNATIONAL JOURNAL OF INNOVATIVE RESEARCH IN TECHNOLOGY
* Compile: g++ quarternarySearch.cpp -o Qsearch -g -Wall (flags optional)
* At present, requires sorted ascending or descending array data entry.
*	 ________________ arr[] ________________
*	|		|		|		|		|
*	|<--x/4-->|<--x/4-->|<--x/4-->|<--x/4-->|
*	|		|		|		|		|
*   low		j		m		p	    high
**************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

int main() {
	int target;							// Search for target.
	int numElem;							// Number of elements in arr[].
	int flag = 0;							// Suppresses not found message. 
	int arr[10000];						// Int buffer.
	string here = "Search int found: ";
	string there = " is located at index position ";

	cout << "Enter the number of elements: ";
	cin >> numElem;

	cout << "Enter the elements of the array:\n";
	for (int i = 0; i < numElem; i++) {
		cin >> arr[i];
	}

	int high = numElem - 1;					// high = value at highest index of arr[].
	int low = 0;
	
	cout << "Enter number to be searched for: ";
	cin >> target;
	
	while (high >= low){
		int j = ((3 * low) + high) / 4;		// j = first quarter index point of arr[].
		int m = (high + low) / 2;			// m = midpoint index of arr[].
		int p = ((3 * high) + low) / 4;		// p = 3rd quarter index point of arr[].

		if (arr[j] == target) {
			cout << here << arr[j] << there << j << ".\n";
			flag = 1;
			low = high + 1;				// Enables exit from while loop.
		}
		else if (arr[m] == target) {
			cout << here << arr[m] << there << m << ".\n";
			flag = 1;
			low = high + 1;				// Enables exit from while loop.
		}
		else if (arr[p] == target) {
			cout << here << arr[p] << there << p << ".\n";
			flag = 1;
			low = high + 1;				// Enables exit from while loop.
		}
		else if (target < arr[j]) {
			high = j - 1;					// Remove 3/4 of arr[] from the search!
		}
		else if (target < arr[m]) {
			low = j + 1;					// Remove 1/4 of arr[] from the search!
			high = m - 1;					// Remove 2/4 of arr[] from the search!
		}
		else if (target < arr[p]) {
			low = m + 1;					// Remove 2/4 of arr[] from the search!
			high = p - 1;					// Remove 1/4 of arr[] from the search!
		}
		else {
			low = p + 1;					// Remove 3/4 of arr[] from the search!
		}
	}
	cin.get();
	if (!flag) {
		cout << "Searched for integer, " << target << ", not found!\n";
	}
}