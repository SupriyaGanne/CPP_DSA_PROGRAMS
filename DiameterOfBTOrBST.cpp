#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the diameter of the tree
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Function to perform level order traversal of the tree


int main() {
    Node* root = NULL;
    int numNodes, data;
    
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    
    for (int i = 0; i < numNodes; i++) {
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> data;
        root = insert(root, data); 
    }
    
    cout << "Diameter of the tree is: " << diameter(root) << endl;
    
    return 0;
}
