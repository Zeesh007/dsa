//Problem Statemnet : 
//Convert given binary tree
//into threaded binary tree. Analyze time and space complexity of the algorithm.
//Concept : A common approach to convert a binary tree into a threaded binary tree is to perform an and, during that traversal, adjust the pointers of nodes that have null left or right children.

#include <iostream>
using namespace std;
struct Node {
int data;
Node* left;
Node* right;
bool lThread;
bool rThread;
};

Node* newNode(int data) {
Node* node = new Node();
node->data = data;
node->left = node->right = NULL;
node->lThread = node->rThread = false;
return node;
}
Node* prv = NULL;

void createThreaded(Node* root) {
if (root == NULL)
return;

createThreaded(root->left);

if (root->left == NULL) {
root->left = prv;
root->lThread = true;

}

if (prv != NULL && prv->right == NULL) {
prv->right = root;
prv->rThread = true;
}

prv = root;
createThreaded(root->right);
}

Node* leftMost(Node* root) {
if (root == NULL)
return NULL;

while (root->lThread == false && root->left != NULL)
root = root->left;

return root;
}

void inOrder(Node* root) {
Node* cur = leftMost(root);
while (cur != NULL) {
cout << cur->data << " ";

if (cur->rThread)
cur = cur->right;
else
cur = leftMost(cur->right);
}

}

int main() {
Node* root = newNode(6);
root->left = newNode(3);
root->right = newNode(8);
root->left->left = newNode(1);
root->left->right = newNode(5);
root->right->right = newNode(11);

createThreaded(root);
cout << "Inorder Traversal of Threaded Binary Tree: ";
inOrder(root);
cout << endl;

return 0;
}
