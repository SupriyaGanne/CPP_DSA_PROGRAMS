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

       
 node* RemoveHalfNodes(node* root){
    if(root==NULL){
        return NULL;
    }
    root->left=RemoveHalfNodes(root->left);
    root->right=RemoveHalfNodes(root->right);
    if(root->left==NULL &&root->right==NULL){
        return root;
    }
    if(root->left==NULL){
        node* new_node=root->right;
        free(root);
        return new_node;
    }
    if(root->right==NULL){
        node* new_node=root->left;
        free(root);
        return new_node;
    }
    return root;


 }
 void LevelOrder(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left!=NULL){
            q.push(t->left);
        }
        if(t->right!=NULL){
            q.push(t->right);
        }
    }
 }

int main(){
    struct node* root = NULL;
    int num_nodes, data;
    cout<<"Enter num_nodes: ";
    cin>>num_nodes;
    for(int i = 0; i < num_nodes; i++){
        cout<<"Enter the value "<<i + 1<<": ";
        cin>>data;
        root = insert(root, data); 
    }
    RemoveHalfNodes(root);
    cout<<"node values after deleting the halfnodes ";
    LevelOrder(root);
    

}

