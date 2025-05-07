//A book consists of chapters, chapters consist of sections and sections consist of
//subsections. Construct a tree and print the nodes. Find the time and space requirements
//of your method.
//
//
//Solution :
#include <iostream>
#include <string>
#define nullptr NULL

using namespace std;

// Tree Node class
struct TreeNode {
   
    string name;           // Node name (e.g., Chapter, Section, Subsection)
    TreeNode* firstChild;  // Pointer to the first child
    TreeNode* nextSibling; // Pointer to the next sibling

    // Constructor to initialize a node
    TreeNode(string name) : name(name), firstChild(nullptr), nextSibling(nullptr) {}
};

// Function to add a child node
void addChild(TreeNode* parent, string childName) {
    TreeNode* child = new TreeNode(childName);

    // If the parent has no children, make this the first child
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    } else {
        // Traverse the sibling chain to add this node as the last sibling
        TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Function to print the tree (DFS Traversal)
void printTree(TreeNode* node, int depth = 0) {
    if (node == nullptr) return;

    // Print indentation based on depth
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << node->name << endl;

    // Print all children of the current node
    printTree(node->firstChild, depth + 1);

    // Print the next sibling of the current node
    printTree(node->nextSibling, depth);
}

// Function to delete the tree (free memory)
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;

    // Recursively delete children and siblings
    deleteTree(node->firstChild);
    deleteTree(node->nextSibling);

    // Delete the current node
    delete node;
}

int main() {
    // Create the root node (Book)
    TreeNode* book = new TreeNode("Book");

    // Add chapters
    addChild(book, "Chapter 1");
    addChild(book, "Chapter 2");

    // Add sections to Chapter 1
    addChild(book->firstChild, "Section 1.1");
    addChild(book->firstChild, "Section 1.2");

    // Add subsections to Section 1.1
    addChild(book->firstChild->firstChild, "Subsection 1.1.1");
    addChild(book->firstChild->firstChild, "Subsection 1.1.2");

    // Add sections to Chapter 2
    addChild(book->firstChild->nextSibling, "Section 2.1");

    // Print the tree
    cout << "Tree Structure of the Book:" << endl;
    printTree(book);

    // Free the allocated memory
    deleteTree(book);
 // Print the tree
    cout << "Tree Structure of the Book After Delete:" << endl;
    printTree(book);
    return 0;
}
