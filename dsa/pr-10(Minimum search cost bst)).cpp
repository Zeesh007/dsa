//Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each
//key ki . Build the Binary search tree that has the least search cost given the access
//probability for each key?
//Solution:
//Here we are using the concept of   using . The algorithm constructs a BST that minimizes the expected search cost given a sorted sequence of keys and their access probabilities.  
//: We use to compute the minimum search cost for a subtree rooted at each key.
//: Using a table to track the of optimal subtrees.
//: Recursively construct the BST from the computed tables.C++ Code

#include<iostream>
#include<limits> // For numeric_limits
using namespace std;

#define MAX 100 // Define a max limit for keys

// Function to calculate sum of probabilities in a given range
double sum(double p[], int i, int j) {
double s = 0;
for (int k = i; k <= j; k++)
s += p[k];
return s;
}

// Function to construct an optimal binary search tree
void optimalBST(int keys[], double p[], int n) {
double cost[MAX][MAX] = {0}; // DP table for cost
int root[MAX][MAX] = {0}; // DP table for root nodes

// Initialize the cost for single keys
for (int i = 0; i < n; i++) {
cost[i][i] = p[i]; // When subtree has only one node
root[i][i] = i; // Root is itself
}

// Compute the optimal cost for larger subtrees
for (int L = 2; L <= n; L++) { // L = subtree size
for (int i = 0; i <= n - L; i++) {
int j = i + L - 1;
cost[i][j] = numeric_limits<double>::max(); // Set to maximum value


// Try every key as root from i to j
for (int r = i; r <= j; r++) {
double c = ((r > i) ? cost[i][r - 1] : 0) +
((r < j) ? cost[r + 1][j] : 0) +
sum(p, i, j);

// Update cost and root if this configuration is optimal

if (c < cost[i][j]) {
cost[i][j] = c;
root[i][j] = r;
}
}
}
}

// Display the root matrix
cout << "\nRoot Matrix:\n";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (i <= j)
cout << root[i][j] + 1 << " "; // Print root indices (1-based)
else
cout << " ";
}
cout << endl;
}

// Display the minimum search cost
cout << "\nMinimum Search Cost: " << cost[0][n - 1] <<
endl;
}

// Driver function
int main() {
int keys[MAX] = {10, 20, 30, 40, 50}; // Sorted keys
double probabilities[MAX] = {0.1, 0.2, 0.4, 0.3, 0.5, 0.8};
// Search probabilities
int n = 5; // Number of keys

optimalBST(keys, probabilities, n);

return 0;
}
