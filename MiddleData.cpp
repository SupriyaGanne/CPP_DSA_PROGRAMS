#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void insert(node* &head,int x){
    node* p=new node;
    p->data=x;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }else{
        p->next=head;
        head=p;
    }
    
}
void middle(node* &head){
    node* p1=head;
    node* p2=head;
    while(p2!=NULL && p2->next!=NULL){
        p1=p1->next;
        p2=p2->next->next;
    }
    cout<<"middle data is"<<" "<<p1->data;
}
int main(){
    node* head=NULL;
    int num_nodes,data;
    cout<<"enter no.of nodes ";
    cin>>num_nodes;
    for(int i=0;i<num_nodes;i++){
        cout<<"enter the value "<<i+1<<" ";
        cin>>data;
        insert(head,data);
    }
    middle(head);
}