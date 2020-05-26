#include <iostream>
using namespace std;
class node{                 // For the construction of One Node we have created the dataType of Node
    public:                 // default is private hence we created it Public
    int data;               // A single node contains a int data and node*next which contains the address of next node.
    node*next;

    node(int d){            // Constructor for node Function
        data=d;
        next=NULL;          // next pointer can be NULL always.
    }
};

// Since we have already created a Node 


void insertAtNode(node*&head, int data){  // Node Head has been given in the main function as Value hence passing by the value.
    node*n= new node(data);  // Dynamically create the new Node.
    n-next= head;            // Since A Node contains a int data + Next Node Pointer. Hence the next node could be head;
    head=n;                  // Head again is N. Since we can store more data into the head. and this head of node contains the int data+ next node*pointer.
}
void Print(node*head){
    while(head!NULL){       // Till the Head is not NULL we will print all the values of head.
    cout<<head->data<<"->";  // Printing the head node associated with the data and int data which was int data=d.
    head= head->next;       //.... Again head is now pointing to the next node.
    }
}
int main()
{
    node*head=NULL;  // It could be possible that the head node contains NULL Value.
    insertAtNode(head,5);
    insertAtNode(head,8);
    insertAtNode(head,3);
    print(head);
}
