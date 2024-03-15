#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    struct node* left,*right;
};
struct node* newNode(int item){
    node* temp=new node;
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert(node* &root,int data){
    if(root==NULL){
        root= newNode(data);
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);

    }
    return root;
}
void levelOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node * t=q.front();
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
    struct node* root=NULL;
    int num_nodes,data;
    cout<<"Enter number of nodes"<<" ";
    cin>>num_nodes;
    for(int i=0;i<num_nodes;i++){
        cout<<"Enter the value"<<i+1<<" ";
        cin>>data;
        insert(root,data);
    }
    levelOrderTraversal(root);
}