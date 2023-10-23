#include <bits/stdc++.h>
using namespace std;

class node{

    public: 
        int value ;
        node* next ;

        node(int data){
            value = data;
            next = NULL;
        }
};

// inserting at the head
void insertAtHead( node* &head, int val){          // take by reference as we have to change the value of head
    node* new_node = new node(val);                
    new_node-> next = head ;
    head = new_node;
}

// inserting at the tail
void insertAtTail(node* &head, int val){

    node* new_node =  new node(val) ;
    node* temp = head;
    
    while(temp->next!=NULL){
        temp = temp->next;
        
    }
    // temp has reached last node
    temp->next = new_node;                             // already points to NULL by the constuctor

}

// to insert the kth node 
void insertAtPosition(node* head, int val, int pos){

    if(pos ==0 ) {
        insertAtHead( head, val) ;
        return ;
    }

    node* new_node = new node(val) ;
    node* temp = head;
    int cur_pos = 0;

    while(cur_pos!=pos-1){
        temp = temp->next;
        cur_pos++;
    }

    // temp is pointing to pos-1

    new_node->next = temp->next;
    temp->next = new_node;
    
}
 
// to update at kth node
void updateAtPosition(node* head, int val, int pos){

    node* temp = head;
    int curr_pos = 0;
    
    while(curr_pos!=pos){

        temp = temp->next;
        curr_pos++; }

    temp->value = val;
}

// to delete at head
void deleteAtHead(node* &head){

    node* temp = head;

    head = temp->next;
    delete temp;
}

// to delete at the last
void deleteAtTail(node* head){

    node* second_last = head;
    while(second_last->next->next != NULL){
        second_last= second_last->next;
    }

    node* temp = second_last->next;
    second_last->next = NULL;

    delete temp;

}

// to print all the nodes
void display(node* head){
    node* temp= head;

    while(temp!=NULL){
        cout << temp->value << "->" ;
        temp = temp->next; 
    }
    cout << "NULL" << endl;
}

// to delete at kth position
void deleteAtPosition(node* &head, int pos){

    if(pos==0){
        deleteAtHead(head);
        return;
    }

    node* prev = head;
    int curr_pos = 0;

    while(curr_pos!=pos-1){
        prev= prev->next;
        curr_pos++;
    }
    node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;

}

int main(){

    // node *n = new node(1);

    // cout << n->value << " " << n->next;

    node* head = NULL ;                 // empty linked list

    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,4);
    insertAtPosition(head,5,1);

    display(head);

    updateAtPosition(head,7,1);

    display(head);

    // deleteAtHead(head);
    // deleteAtTail(head);
     deleteAtPosition(head,2) ;

    display(head);


    return 0;
}