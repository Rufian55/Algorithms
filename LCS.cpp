/* Recursive and DP implementations of Longest Common Subsequence with
*  Printing of the actual LCS.
*  Compile: g++ LCS.cpp -o LCS -g -Wall -std=c++0x
*--------------------------------------------------------------------*/
#include<cstring>
using std::strlen;
#include<iostream>
using std::cout;

// Prototypes.
int max(int a, int b);
int LCS_Recur(char *X, char *Y, int m, int n);
int LCS_DP(char *X, char *Y, int m, int n);

int main() {
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);
	cout << "Length of LCS_Recur is " << LCS_Recur(X, Y, m, n) << "\n";
	cout << "Length of LCS_DP is " << LCS_DP(X, Y, m, n) << "\n";
	return 0;
}


/* Recursively returns length of LCS for X[0..m-1], Y[0..n-1] */
int LCS_Recur(char *X, char *Y, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + LCS_Recur(X, Y, m - 1, n - 1);
	else
		return max(LCS_Recur(X, Y, m, n - 1), LCS_Recur(X, Y, m - 1, n));
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] via DP implementation. */
int LCS_DP(char *X, char *Y, int m, int n) {
	int L[m + 1][n + 1];
	int i, j;
	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i = 0; i <= m; i++)	{
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Print LCS.
	int index = L[m][n];

	// Create a c-string to store the lcs string.
	char lcs[index + 1];
	lcs[index] = '\0';

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
	i = m;
	j = n;
	while (i > 0 && j > 0) {
		// If current char in X[] and Y[] are ==, then
		// current char is part of LCS.
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1] = X[i - 1];	// Put current character in result.
			i--; j--; index--;			// Reduce values of i, j and index.
		}
		// If not same, then find the larger of the two and
		// go in the direction of larger value.
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}
	// Print the LCS.
	cout << "LCS of " << X << " and " << Y << " is " << lcs << "\n";

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b) {
	return (a > b) ? a : b;
}
