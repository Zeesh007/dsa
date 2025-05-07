#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#define nullptr NULL

using namespace std;

struct Node {
char data;
Node* left;
Node* right;

Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
return c == '+' || c == '-' || c == '*' || c == '/';
}

Node* constructExpressionTree(const string& prefix) {
stack<Node*> nodeStack;

for (int i = prefix.length() - 1; i >= 0; --i) {
char currentChar = prefix[i];

if (isalnum(currentChar)) {
nodeStack.push(new Node(currentChar));

}
else if (isOperator(currentChar)) {
Node* newNode = new Node(currentChar);
newNode->left = nodeStack.top(); nodeStack.pop();
newNode->right = nodeStack.top(); nodeStack.pop();
nodeStack.push(newNode);
}
}

return nodeStack.top();
}

void postorderTraversal(Node* root) {
if (!root) return;

stack<Node*> s1, s2;
s1.push(root);

while (!s1.empty()) {
Node* node = s1.top();
s1.pop();
s2.push(node);

if (node->left) s1.push(node->left);
if (node->right) s1.push(node->right);
}

while (!s2.empty()) {
cout << s2.top()->data << " ";
s2.pop();
}

cout << endl;
}

void deleteTree(Node* root) {
if (root) {
deleteTree(root->left);
deleteTree(root->right);
delete root;
}
}

int main() {
string prefix = "+--a*bc/def";
Node* root = constructExpressionTree(prefix);
cout << "Postorder Traversal: ";
postorderTraversal(root);
deleteTree(root);

return 0;
}
