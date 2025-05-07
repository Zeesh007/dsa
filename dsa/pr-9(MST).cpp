//Problem Statement :
//You
//have a business with several offices; you want to lease phone lines to connect
//them up with each other; and the phone company charges different amounts of
//money to connect different pairs of cities. You want a set of lines that
//connects all your offices with a minimum total cost. Solve the problem
//by suggesting appropriate data structures.
//Soluntion :
//This problem can be solved using algorithms. The two well-known MST algorithms are and .
//Here,We use , which is well-suited for a sparse graph with weighted edges. The approach involves:Representing the offices as in a graph.Representing the phone line costs as with weights.Using to find the Minimum Spanning Tree (MST).C++

#include <iostream>
#include <algorithm>
#define MAX_EDGES 100
#define MAX_NODES 50
using namespace std;
struct Edge {
int u, v, weight;
};

Edge edges[MAX_EDGES];
int component[MAX_NODES];

bool compareEdges(Edge a, Edge b) {
return a.weight < b.weight;
}

int kruskalMST(int numNodes, int numEdges) {

sort(edges, edges + numEdges, compareEdges);
for (int i = 0; i < numNodes; i++) {
component[i] = i;
}

int minCost = 0, edgesUsed = 0;
for (int i = 0; i < numEdges; i++) {

int u = edges[i].u;
int v = edges[i].v;
int weight = edges[i].weight;

if (component[u] != component[v]) {
minCost += weight;
edgesUsed++;

int oldComponent = component[v];
int newComponent = component[u];

for (int j = 0; j < numNodes; j++) {
if (component[j] == oldComponent) {
component[j] = newComponent;
}
}

if (edgesUsed == numNodes - 1) break;
}
}

return (edgesUsed == numNodes - 1) ? minCost : -1;
}

int main() {
int numNodes, numEdges;
cout << "Enter number of offices (nodes) and connections (edges): ";
cin >> numNodes >> numEdges;

cout << "Enter the edges (u v weight) format:\n";
for (int i = 0; i < numEdges; i++) {
cin >> edges[i].u >> edges[i].v >> edges[i].weight;
}

int minCost = kruskalMST(numNodes, numEdges);

if (minCost != -1)
cout << "Minimum cost to connect all offices: " << minCost << endl;
else
cout << "Not all offices can be connected." << endl;

return 0;
}
