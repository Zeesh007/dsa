//Problem Statment :
//Represent a given
//graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph.
//Identify
//the prominent land marks as nodes and perform
//DFS and BFS on that.

#include <iostream>
#include <queue>
#define MAX 10
using namespace std;
struct Node {
int vertex;
Node* next;
};

class Graph {
private:
int V;
int adjMatrix[MAX][MAX];
Node* adjList[MAX];
public:
Graph(int vertices) {
V = vertices;

for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
adjMatrix[i][j] = 0;
}
adjList[i] = NULL;
}
}

void addEdgeMatrix(int u, int v) {

adjMatrix[u][v] = 1;
adjMatrix[v][u] = 1;
}

void addEdgeList(int u, int v) {

Node* newNode1 = new Node;
newNode1->vertex = v;
newNode1->next = adjList[u];
adjList[u] = newNode1;

Node* newNode2 = new Node;
newNode2->vertex = u;
newNode2->next = adjList[v];
adjList[v] = newNode2;
}

void dfs(int node, bool visited[]) {
cout << node << " ";
visited[node] = true;

for (int i = 0; i < V; i++) {
if (adjMatrix[node][i] == 1 && !visited[i]) {
dfs(i, visited);
}
}
}

void bfs(int start) {
bool visited[MAX] = {false};

queue<int> q;

q.push(start);
visited[start] = true;

while (!q.empty()) {
int node = q.front();
q.pop();
cout << node << " ";

Node* temp = adjList[node];
while (temp) {
int neighbor = temp->vertex;
if (!visited[neighbor]) {
q.push(neighbor);
visited[neighbor] = true;
}
temp = temp->next;
}
}
}
};

int main() {
Graph g(5);
int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}};
int numEdges = sizeof(edges) / sizeof(edges[0]);

for (int i = 0; i < numEdges; i++) {
g.addEdgeMatrix(edges[i][0], edges[i][1]);

g.addEdgeList(edges[i][0], edges[i][1]);
}

cout << "DFS Traversal (Adjacency Matrix): ";
bool visited[MAX] = {false};
g.dfs(0, visited);

cout << "\nBFS Traversal (Adjacency List using Linked List): ";
g.bfs(0);

return 0;
}
