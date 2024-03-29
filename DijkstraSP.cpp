/* A C / C++ program for Dijkstra's single source shortest
*  path algorithm. The program is for adjacency matrix
*  representation of the graph.
*  Compile: g++ DijkstraSP.cpp -o dijkstraSP -g -Wall -std=c++0x
*****************************************************************/
#include <stdio.h>
#include <limits.h>

#define V 8

// Prototypes.
int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j);
int printSolution(int dist[], int n, int parent[]);
void dijkstra(int graph[V][V], int src);

int main() {
    // Create an adjacency matrix graph.
	
          // Vertex # 0  1  2  3  4  5  6  7  8		   Vertex
/*  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },	//   0
                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },	//   1
					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },	//   2	
					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },	//   3
					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },	//   4
					{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },	//   5
					{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },	//   6
					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },	//   7
					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };	//   8

	dijkstra(graph, 0);
*/

			//  Vertex # A  B  C  D  E  F  G  H	   Vertex
  int graph2[V][V] = { { 0, 0, 4, 0, 0, 7, 0, 0 },	//   A
                       { 0, 0, 0, 0, 9, 0, 0, 3 },	//   B
                       { 4, 0, 0, 3, 0, 2, 9, 0 },	//   C	
                       { 0, 0, 3, 0, 3, 0, 7, 0 },	//   D
                       { 0, 9, 0, 3, 0, 0, 2, 7 },	//   E
                       { 7, 0, 2, 0, 0, 0, 8, 0 },	//   F
                       { 0, 0, 9, 7, 2, 8, 0, 3 },	//   G
                       { 0, 3, 0, 0, 7, 0, 3, 0 } };//   H
	
    dijkstra(graph2, 1);

    return 0;
}

// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree.
int minDistance(int dist[], bool sptSet[]) {
    // Initialize min values.
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest path from source to j using parent array.
void printPath(int parent[], int j) {
    // Base Case : If j is source.
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

// A utility function to print the constructed distance array.
int printSolution(int dist[], int n, int parent[]) {
    int src = 0;
    printf("Vertex\t  Distance\t\tPath");
    for (int i = 1; i < V; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
    return 0;
}

// Function that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i
                  // sptSet[i] will true if vertex i is included / in shortest
                  // path tree or shortest distance from src to i is finalized.
    bool sptSet[V];

    // Parent array to store shortest path tree.
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++) {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print the constructed distance array
    printSolution(dist, V, parent);
}
