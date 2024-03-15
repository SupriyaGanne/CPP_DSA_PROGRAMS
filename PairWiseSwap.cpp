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
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
    
}
node* pairwiseswap(node* &head){
    node* p1=head;
    while(p1!=NULL && p1->next!=NULL){
        int temp=p1->data;
        p1->data=p1->next->data;
        p1->next->data=temp;
        p1=p1->next->next;
    }
    return head;
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
    pairwiseswap(head);
    cout<<"After swapping pairwise ,the data is "<<endl;
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}