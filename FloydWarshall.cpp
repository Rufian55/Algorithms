/*****************************************************************************************
* C/C++ program demonstrating a use of the Floyd Warshall algorithm for solving the "all
* pairs" problem in a graph.  This particular implementation seeks to find the locations
* of two fire stations given a road and distance to instersections matrix.  Runs O(v^3)
* Compile: g++ FloydWarshall.cpp -o FW -g -Wall -c++std=0x
******************************************************************************************/
#include <algorithm>
#include<limits.h>
#include<stdio.h>
#include <vector>
using std::vector;

#define V 8
#define INF INT_MAX

// For making the input graph more readable only.
#define N INT_MAX

// Prototypes.
void printSolution(int dist[][V]);
void floydWarshall(int graph[][V]);

int main() {
              // Vertex # A  B  C  D  E  F  G  H    Vertex
    int graph[V][V] = { { 0, N, 4, N, N, 7, N, N }, // A
                        { N, 0, N, N, 9, N, N, 3 }, // B
                        { 4, N, 0, 3, N, 2, 9, N }, // C	
                        { N, N, 3, 0, 3, N, 7, N }, // D
                        { N, 9, N, 3, 0, N, 2, 7 }, // E
                        { 7, N, 2, N, N, 0, 8, N }, // F
                        { N, N, 9, 7, 2, 8, 0, 3 }, // G
                        { N, 3, N, N, 7, N, 3, 0 } };//H

    floydWarshall(graph);
    return 0;
}


// Solves the all-pairs shortest path problem using Floyd Warshall algorithm.
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Avoid integer overflow.
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);

    int temp;
    vector<int> solution;
    for (i = 0; i < V; i++) {
        temp = 0;
        for (j = 0; j < V; j++) {
            if (dist[i][j] > temp) {
                temp = dist[i][j];
            }
        }
        solution.push_back(temp);
    }

    char vertices[V] = { 'A','B','C','D','E','F','G','H' };
    int FS1, FS2;
    char FireStation_1, FireStation_2;

    FS1 = *(std::min_element(solution.begin(), solution.end()));

    auto position = std::find(solution.begin(), solution.end(), FS1);
    int index = std::distance(solution.begin(), position);
    FireStation_1 = vertices[index];

    solution[index] = INF; // Supresses reselection of 1st solution min.

    FS2 = *(std::min_element(solution.begin(), solution.end()));
    position = std::find(solution.begin(), solution.end(), FS2);
    FireStation_2 = vertices[std::distance(solution.begin(), position)];

    printf("FireStation 1 will be %c and FireStation 2 will be %c.\n", FireStation_1, FireStation_2);
}


void printSolution(int dist[][V]) {
    printf("Distances matrix between \"all pairs\" vertices.\n");
    char alpha = 'A';
    char beta = 'A';

    for (int i = 0; i < V; i++) {
        printf("%7c", alpha);
        alpha++;
    }
    printf("\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            }
            else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("%4c", beta);
        beta++;
        printf("\n");
    }
}
