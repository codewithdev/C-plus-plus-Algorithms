// implementation of doubly linked list

#include <bits/stdc++.h>
using namespace std;

class Node{

   public:
    int data;
    Node* prev;
    Node* next;

    Node(int val ){
        data = val;
        prev =  NULL;
        next = NULL;
    }
};

class DoublyLL{

public:
    Node* head ;
    Node* tail ;

    DoublyLL(){
        head = NULL;
        tail = NULL;
    }

    // to display the linked list
    void display(){

        Node* temp = head;

        while(temp!=NULL){
            cout << temp->data << "<->" ;
            temp = temp->next;
        }
        cout <<endl ;

    }

    // insertion start position 
    void insertAtStart(int data){

        Node* new_node = new Node(data);

        if(head == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        
        return;
    }

    void insertAtEnd(int data){

        Node* new_node = new Node(data);

        if(tail==NULL){
            head = new_node;
            tail = new_node;
            return ;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void insertAtKthPosition(int data , int k){

        Node* new_node = new Node(data);
        int ptr = 1;
        Node* temp =head;

        while(ptr<k-1){
            temp = temp->next ;
            ptr++;
        }

        new_node->next = temp->next;
        temp->next = new_node;

        new_node->next->prev = new_node ; 
        new_node->prev = temp;

    }

    void deleteAtStart(){
 
        if(head == NULL) return ;

        Node* temp = head;
        head = head->next;
       

        // only one node was their in the likedlist
        if(head==NULL) {
            tail = NULL;
        } 

        else head->prev = NULL;

        delete temp;
    }

    void deleteAtEnd(){

        if(tail == NULL) return;

        Node* temp = tail;
        tail = temp->prev;
        
        if(tail == NULL){
            head = NULL;
        }
        else tail->next = NULL;

        delete temp;
    }

    void deleteAtKth(int k){

        Node* temp = head;
        int cnt = 1;

        if(temp == NULL) return;

        if(k==1) {
            deleteAtStart();
            return;
        }

        while(cnt<k && temp){  
            temp = temp->next;
            cnt++;
        }

        if(temp == tail) {
            deleteAtEnd();
            return;
        } 
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

    }
};

     void reverseDoublyLL(Node* &head, Node* &tail){

        Node* curr = head;

        while(curr){
            
            Node* next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;

            curr = next;
        }

        // swapping the head and tail
        Node* new_head = tail;
        tail = head;
        head = new_head;
    }

    bool isPalindrome(Node* &head, Node* tail){

        Node* temp1 = head;
        Node* temp2= tail;

        while(temp1<temp2){

            if(temp1->data!=temp2->data) return false;
            temp1= temp1->next;
            temp2 = temp2->prev;
        }

        return true;
    }

int main(){

    // Node* new_node = new Node(3);

    // DoublyLL dll;

    // dll.head = new_node;
    // dll.tail  = new_node;

    // cout << dll.head->data ;

    DoublyLL dll;

    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);

    dll.display();

    // dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);

    dll.display();

    // dll.insertAtKthPosition(10,4);
    // dll.display();

    // dll.deleteAtEnd();
    // dll.display();

    // dll.deleteAtKth(2);
    // dll.display();

    // reverseDoublyLL(dll.head, dll.tail);
    // dll.display();

    cout << isPalindrome(dll.head, dll.tail);




}

