/* Recursive Θ(2^n), Dynamic Θ(nW) implementations of 0-1 Knapsack problem.
*  Compile: gcc knapSack.c -o knapSack -g -Wall
*  See fractionalKnapSack as well.
***************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

// Prototypes.
int knapSack(int capacity, int weight[], int value[], int n);
int knapSackRecur(int capacity, int weight[], int value[], int n);
int max(int a, int b);

int main() {
    int value[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int  capacity = 50;
    int n = sizeof(value) / sizeof(value[0]);
    printf("Recursive knapSack solution = %d\n", knapSackRecur(capacity, weight, value, n));
    printf("DP knapSack solution = %d\n", knapSack(capacity, weight, value, n));
    return 0;
}

// Dynamic Programming solution for 0-1 Knapsack problem. Θ(nW) [Weight].
int knapSack(int capacity, int weight[], int value[], int n){
    int i, w;
    int kSack[n + 1][capacity + 1];

    // Build table kSack[][] bottom up.
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                kSack[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {
                kSack[i][w] = max(value[i - 1] + kSack[i - 1][w - weight[i - 1]], kSack[i - 1][w]);
            }
            else {
                kSack[i][w] = kSack[i - 1][w];
            }
        }
    }
    return kSack[n][capacity];
}

// Recursively compute and return the max value that can be put in a knapsack of capacity W. Θ(2^n)
int knapSackRecur(int capacity, int weight[], int value[], int n) {
    // Base Case.
    if (n == 0 || capacity == 0) { return 0; }

    /* If weight of the nth item is more than Knapsack capacity W,
       then the item cannot be included in the optimal solution. */
    if (weight[n - 1] > capacity) {
        return knapSackRecur(capacity, weight, value, n - 1);
    }
    // Return max of 2 cases: (1) nth item included, (2) not included.
    else {
        return max(value[n - 1] + knapSackRecur(capacity - weight[n - 1], weight, value, n - 1), knapSackRecur(capacity, weight, value, n - 1));
    }
}

// Returns max of two ints.
int max(int a, int b) {
    return (a > b) ? a : b;
}
