/******************************************************************************
*  C++ program for Dijkstra's single source shortest path algorithm. The
*  program is for an adjacency matrix representation of the graph. Runs O(V^2)
*  Compile: g++ DijkstraSP_3.cpp -o dijkstraSP_3 -g -Wall -std=c++0x
*****************************************************************************/
#include <stdio.h>
#include <limits.h>
#include <vector>
using std::vector;

// Number of vertices in the graph
#define V 8

// Protoypes.
int minDistance(int dist[], bool sptSet[]);
int printSolution(int dist[], int n);
void dijkstra(int graph[V][V], int src, vector<int> &solution);

// driver program to test above function
int main() {
	// Vector of max distances for each vertex as source.
	vector<int> solution;

	//		    Vertex # A  B  C  D  E  F  G  H	   Vertex
	int graph2[V][V] = { { 0, 0, 4, 0, 0, 7, 0, 0 },	//   A
					 { 0, 0, 0, 0, 9, 0, 0, 3 },	//   B
					 { 4, 0, 0, 3, 0, 2, 9, 0 },	//   C	
					 { 0, 0, 3, 0, 3, 0, 7, 0 },	//   D
					 { 0, 9, 0, 3, 0, 0, 2, 7 },	//   E
					 { 7, 0, 2, 0, 0, 0, 8, 0 },	//   F
					 { 0, 0, 9, 7, 2, 8, 0, 3 },	//   G
					 { 0, 3, 0, 0, 7, 0, 3, 0 } };//   H

	for (int i = 0; i < V; i++)
		dijkstra(graph2, i, solution);

	char vertices[V] = { 'A','B','C','D','E','F','G','H' };

	for (unsigned int i = 0; i < solution.size(); i++) {
		printf("Max path distance from Vertex %c = %d\n", vertices[i], solution[i]);
	}

	return 0;
}


/* Implements Dijkstra's single source shortest path algorithm for a graph
   represented by an adjacency matrix. */
void dijkstra(int graph[V][V], int src, vector<int> &solution) {
	int dist[V];     // The output array.  dist[i] will hold the shortest
				  // distance from src to i

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
				 // path tree or shortest distance from src to i is finalized

				 // Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

//	int i;
//	printf("dist[] = ");
//	for (i = 0; i < V; i++) {
//		printf("%d ", dist[i]);
//	}
//	printf("\n");

	int temp = 0;
//	printf("max dist[] = ");
	for (int i = 0; i < V; i++) {
		if (dist[i] > temp)
			temp = dist[i];
	}
	solution.push_back(temp);
//	printf("%d\n", temp);

	// print the constructed distance array
	printSolution(dist, V);
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


// A utility function to print the constructed distance array
int printSolution(int dist[], int n) {
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
	return 0;
}

//* Adapted from: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/