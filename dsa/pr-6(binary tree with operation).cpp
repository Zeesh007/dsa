//Problem Statment :
//Beginning
//with an empty binary search tree, Construct binary search tree by inserting the values in the
//order given. After constructing a binary tree -
//
//i. Insert new node, 
//ii. Find number of nodes in
//longest path from root, 
//iii. Minimum data value found in the tree, 
//iv. Change a tree so that the roles of the left
//and right pointers are swapped at every node,
//v. Search a value
#include <iostream>
#define nullptr NULL
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
   
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (!root)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Function to find the height (longest path) of the tree
int findHeight(Node* root) {
    if (!root)
        return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    return maxHeight + 1;
}

// Function to find the minimum value in the tree
int findMin(Node* root) {
    if (!root)
        return -1; // If tree is empty
    while (root->left)
        root = root->left;
    return root->data;
}

// Function to mirror (swap left and right) the tree
void mirrorTree(Node* root) {
    if (!root)
        return;
   
    // Swap left and right manually without using swap()
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (!root)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

// Function to print the tree (inorder traversal)
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int v=0;v<7;v++){
	int te=values[v];
	root = insert(root,te);
	}
    cout << "BST Inorder Traversal: ";
    inorder(root);
    cout << endl;

    root = insert(root, 25);
    cout << "After inserting 25, Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Number of nodes in longest path: " << findHeight(root) << endl;
    cout << "Minimum value in the tree: " << findMin(root) << endl;

    mirrorTree(root);
    cout << "Inorder after mirroring: ";
    inorder(root);
    cout << endl;

    int searchValue = 60;
    cout << "Searching for " << searchValue << ": " << (search(root, searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}
