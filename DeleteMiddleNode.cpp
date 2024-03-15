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
void deletemiddle(node* &head){
    node* p1=head;
    node* p2=head;
    node* prev=NULL;
    while(p2!=NULL && p2->next!=NULL){
        p2=p2->next->next;
        prev=p1;
        p1=p1->next;
    }
    prev->next = p1->next; 
    free(p1);
    cout<<"Number of nodes after deleting the middle node"<<":";
    node* current1=head;
    int c1=0;
    while(current1!=NULL){
        c1++;
        current1=current1->next;
    }
    cout<<c1<<endl;
    
}
int main(){
    node* head=NULL;
    int num_nodes,data;
    cout<<"enter no.of nodes";
    cin>>num_nodes;
    for(int i=0;i<num_nodes;i++){
        cout<<"enter the value "<<i+1<<":";
        cin>>data;
        insert(head,data);
    }
    cout<<"before deleting number of nodes in Linkedlist are"<<":";
    
    node* current=head;
    int c=0;
    while(current!=NULL){
        c++;
        current=current->next;
    }
    cout<<c;
    deletemiddle(head);
}