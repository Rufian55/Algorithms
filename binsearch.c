/*************************************************************
* binsearch.c is the classic binary search algorithm. Returns
* array index if found, -1 otherwise...
**************************************************************/
#include <stdio.h>
#include <assert.h>

int binsearch(int hayStack[], int length, int needle) {
    int low = 0;
    int high = length-1;
    int mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(hayStack[mid] == needle) {
            return mid;
        }
        else if (needle < hayStack[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

void test() {
    int hayStack[7] = { 2, 4, 6, 8, 10, 12, 14 };
    int len = sizeof(hayStack) / sizeof(int);
    int index = binsearch(hayStack, len, 4);
    assert(index == 1);

	index = binsearch(hayStack, len, 2);
    assert(index == 0);
        
	index = binsearch(hayStack, len, 10);
    assert(index == 4);
        
	index = binsearch(hayStack, len, 14);
    assert(index == 6);
       
	index = binsearch(hayStack, len, 28);
    assert(index == -1);
}

int main() {
    test();
    return 0;
}
