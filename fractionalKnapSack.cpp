/* Returns fractional Knapsack Solution.
* Compile: g++ fractionalKnapSack.cpp -o FracKnapSack -g -Wall -std=c++0x */
#include<iostream>
using std::cout;
#include<algorithm>
using std::sort;

/* Stucture for Item for storing weight and corresponding
*  value of Item */
struct Item {
	int value, weight;
	// Constructor
	Item(int value, int weight) : value(value), weight(weight) {};
};

// Prototypes.
bool cmp(struct Item a, struct Item b);
double fractionalKnapsack(int capacity, struct Item arr[], int n);

int main() {
	int capacity = 50; // Weight of knapsack
	Item arr[] = { {60,10}, {100,20}, {120,30} };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum value in fractional Knapsack = " << fractionalKnapsack(capacity, arr, n) << "\n";
	return 0;
}


// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b){
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

// Greedy method to solve fractional knapsack problem.
double fractionalKnapsack(int capacity, struct Item arr[], int n) {
	// Sort Item on basis of ratio.
	sort(arr, arr + n, cmp);
	// Show new order of Items with their ratio.
	for (int i = 0; i < n; i++) {
		cout << arr[i].value << " " << arr[i].weight << " : "	
			<< ((double)arr[i].value / arr[i].weight) << "\n";
	}
	int curWeight = 0; // Current weight in knapsack
	double finalValue = 0.0; // Result (value in Knapsack)
	// Looping through all Items
	for (int i = 0; i < n; i++) 	{
		// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= capacity) {
			curWeight += arr[i].weight;
			finalValue += arr[i].value;
		}
		// If we can't add current Item, add fractional part of it
		else {
			int remain = capacity - curWeight;
			finalValue += arr[i].value * ((double)remain / arr[i].weight);
			break;
		}
	}
	// Returning final value
	return finalValue;
}


