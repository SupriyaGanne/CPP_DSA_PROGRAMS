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
void zigzagtraversal(node* root){
    if(root==NULL){
        return ;
    }
    stack<node*>cl;
    stack<node*>nl;
    cl.push(root);
    bool flag=true;
    while(!cl.empty()){
        node* temp=cl.top();
        cl.pop();
        if(temp!=NULL){
            cout<<temp->data;
            if(flag){
                if(temp->left!=NULL){
                nl.push(temp->left);
            }
                if(temp->right!=NULL){
                    nl.push(temp->right);
                }
            }
            else{
                if(temp->right!=NULL){
                    nl.push(temp->right);
                }
                if(temp->left!=NULL){
                    nl.push(temp->left);
                }
        }
        if(cl.empty()){
            flag=!flag;
            swap(cl,nl);
        }
        
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
    zigzagtraversal(root);
    
}
