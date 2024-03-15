
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
        node* p1=new node;
        p1=head;
        while(p1->next!=NULL){
            p1=p1->next;
        }
        p1->next=p;
        p->next=NULL;
    }
}

int divide(node* &head, int data) {
    node* evenstart = NULL;
    node* evenend = NULL;
    node* oddstart = NULL;
    node* oddend = NULL;
    node* temp = head;
    
    while (temp != NULL) {
        if ((temp->data) % 2 == 0) {
            if (evenstart != NULL) {
                evenend->next = temp;
                evenend = temp;
            } else {
                evenstart = temp;
                evenend = temp;
            }
        } else {
            if (oddstart != NULL) {
                oddend->next = temp;
                oddend = temp;
            } else {
                oddstart = temp;
                oddend = temp;
            }
        }
        temp = temp->next;
    }

    if (evenstart == NULL && oddstart == NULL) {
        if (head != NULL) {
            cout << head->data;
        }
    } else {
        if (oddstart != NULL) {
            head = evenstart;  // Start with even numbers
            evenend->next = oddstart;  // Connect even numbers to odd numbers
            oddend->next = NULL;  // Terminate the list after odd numbers
        } else {
            head = evenstart;  // If there are no odd numbers, just use even numbers
        }
    }

    node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
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
   divide(head,data);
}
