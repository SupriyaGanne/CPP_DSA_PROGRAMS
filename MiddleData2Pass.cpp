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
void findmiddle(node* &head){
    node* p1=head;
    int l=0;
    while(p1!=NULL){
        l++;
        p1=p1->next;
    }
    int c=0;
    node* p2=head;
    while(c<l/2){
        p2=p2->next;
        c++;
        
    }
    if(l%2==0){
    cout<<p2->next->data;
    }else{
        cout<<p2->data;
    }
}
int main(){
    node* head=NULL;
    int num_nodes,data;
    cout<<"enter no.of nodes ";
    cin>>num_nodes;
    for(int i=0;i<num_nodes;i++){
        cout<<"enter the value "<<i+1<<endl;
        cin>>data;
        insert(head,data);
    }
    findmiddle(head);
}