#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int d){
        data=d;
        node*next= NULL;
    }
};

//Passing a pointer variable by reference

void insertAtHead(node*&head, int data){
   node*n= new node(data);
   n->next = head;
   head= n;
}
int length(node*head){
    int len=0;
    while(head!=NULL){
        head= head->next;
        len+=1;
    }
    return len;
}
void insertAtTail(node*&head, int data){
    if(head==NULL){
        head= new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL){
        tail= tail->next;
    }
    tail->next= new node(data);
    return;
}
void insertAtMiddle(node*&head, int data, int p)
{
    if(head==NULL || p==0){
        insertAtHead(head,data);
    }
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        int jump=1;
        node*temp= head;
        while(jump<=p-1){
        temp= temp->next;
        jump+=1;
        }
        node*n= new node(data);
        n->next= temp->next;
        temp->next=n;
    }
}
bool searchRecursive(node*head, int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}
bool searchIteratively(node*head, int key){
    if(head==NULL){
        return false;
    }
    while(head!=NULL){
        if(head==key){
            return true;
        }
}
void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp= head;
    head= head->next;
    delete temp;
    return;
}
}
void printNode(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<endl;
}
node*mid(node*head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  node*slow=head;
  node*fast= head->next;
  while(fast!=NULL and fast-next!=NULL){
    fast= fast->next->next;
    slow= slow->next->next;
  }
  return slow;
}


bool detectCycle(node*head){
    node*slow= head;
    node*fast= head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow= slow->next;
        if(fast==slow){
            return true;
        }
        return false;
    }
}

int main()
{
    node*head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtHead(head,1);
    insertAtMiddle(head,4,2);
    printNode(head);
    if(detectCycle()){
        cout<<"Cycle is formed";
    }
    else{
        cout<<"Cycle is not Found";
    }
}