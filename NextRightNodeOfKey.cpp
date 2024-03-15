#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node* left, *right;
};

struct node* newNode(int item){
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void NextRightNode(node* root, int key){
    if(root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }
    queue<node*> q;
    q.push(root);
    bool keyFound = false;
    
    while(!q.empty()){
        int levelSize = q.size();
        bool foundInLevel = false;
        
        while(levelSize--) {
            node* t = q.front();
            q.pop();
            
            if(t != NULL) {
                if(keyFound && !foundInLevel) {
                    cout << t->data << " ";
                    foundInLevel = true;
                }
                if(t->data == key) {
                    keyFound = true;
                }
                if(t->left != NULL) {
                    q.push(t->left);
                }
                if(t->right != NULL) {
                    q.push(t->right);
                }
            }
        }
        if(foundInLevel) {
            return;
        }
    }
    
    cout << "No right node found for key " << key << endl;
}

int main(){
    struct node* root = NULL;
    int num_nodes, data, key;
    cout << "Enter num_nodes: ";
    cin >> num_nodes;
    cout << "Enter key value: ";
    cin >> key;
    
    for(int i = 0; i < num_nodes; i++){
        cout << "Enter the value " << i + 1 << ": ";
        cin >> data;
        root = insert(root, data); 
    }
    
    cout << "Next right node(s) for key " << key << ": ";
    NextRightNode(root, key);
    
    return 0;
}
