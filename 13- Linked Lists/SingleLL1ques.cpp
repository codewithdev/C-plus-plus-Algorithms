#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Linkedlist{
    public:
        Node* head;                               // head is common so don't need to put in every function

        Linkedlist(){                              // when we initailize the linkedlist
            head = NULL;   
        }

        void insertAtTail(int val){

            Node* new_node = new Node(val);

            if(head==NULL) {                        // if linkedlist is empty;
                head = new_node;
                return;
            }

             Node* temp = head;

            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }

        void display(){
            
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" <<endl;
        }
};


    void alternateDelete(Node* &head) {

        Node* curr = head;

        while(curr!=NULL && curr->next!=NULL){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            curr = curr->next;
        }
    }

    void sorteddelDuplicates(Node* &head){

        Node* curr = head;

        while(curr!=NULL){

            while(curr->next && curr->data == curr->next->data) {
                Node* temp = curr->next;                                         // node to be deleted
                curr->next = curr->next->next;
                delete temp;
            }
            curr = curr->next;
        }
    }

    void displayrev(Node* head){

        if(head == NULL) {
            cout << "NULL->" ;
            return ;
        }

        displayrev(head->next);
        cout << head->data << "->" ;
    }

    Node* revLinkedList(Node* &head){

        Node* prev = NULL;
        Node* curr = head;                     // put curr->next = prev and move all 3 pointers by 1 step

        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // head= prev;
        Node* new_head = prev;
        return new_head;
    }

    Node* revRecurinkedList(Node* head) {

        // base case
        if(head == NULL || head->next==NULL) return head ;   // only one node left

        Node* new_head = revRecurinkedList(head->next);

        head->next->next = head;
        head->next=NULL;

        return new_head;

    }

    Node* reverseKLL(Node* head, int k){

        // first reverse iteratively the k elements
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 0;

        while(curr!=NULL && cnt<k){

            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
            cnt++;
        }

        if(curr!=NULL){
            Node* new_head = reverseKLL(curr, k) ;        // curr will be its head
            head->next = new_head ;
        }

        return prev;
    }

    // check if two linked list are equal or not
      bool checkEqualLL(Node* head1, Node* head2){

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        while(ptr1!=NULL && ptr2!=NULL) {

            if(ptr1->data!=ptr2->data) return false;

            ptr1=ptr1->next;
            ptr2=ptr2->next;

        }
          return (ptr1==NULL && ptr2 == NULL) ;

    }

    // to get length 
    int getlength(Node* head){

        Node* temp = head;
        int len = 0;

         while(temp!=NULL) {
            len++;
            temp = temp->next;
        }

        return len;
    }

    // check the intersection points of two linked list
    Node* getIntersection(Node* head1, Node* head2){

        // to calculate length of each node
        Node* ptr1 = head1;
        Node* ptr2 = head2;

        int l1=getlength(ptr1), l2=getlength(ptr2);

        int diff = abs(l1-l2);

        if(l1>l2) { while(diff) {
            ptr1 = ptr1->next;
            diff--; }
        }

        if(l2>l1) { while(diff) {
            ptr2 = ptr2->next;
            diff--; }
        }

        while(ptr1!=NULL) {

            if(ptr1->data == ptr2->data) return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        return NULL;
        
    }

    //delete from last
    void deletefromLast(Node* &head, int k){

        // Node* temp = head;

        // int len = getlength(head);
        // int ptr = len-k;

        // if(ptr==0) return (head=head->next);

        // while(ptr>1) {
        //     temp= temp->next;
        //     ptr--;
        // }

        // temp->next = temp->next->next;

        // return head;

        Node* ptr1 = head;
        Node* ptr2 = head;

        int cnt = k;

        while(cnt--){
            ptr2 = ptr2->next;
        }

        // k is eual to the length of the linked list
        if(ptr2==NULL) {
            Node* temp = head;
            head= head->next;
            delete temp;
        } 


        while(ptr2->next!=NULL){

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        Node* temp = ptr1->next; 
        ptr1->next = ptr1->next->next;
        delete temp;

    }

    // to merge two linked list
    Node* mergeLL(Node* &head1, Node* &head2){

        Node* dummy_head = new Node(-1);

        Node* ptr1 = head1;
        Node* ptr2 = head2;
        Node* ptr3 = dummy_head;

        while(ptr1!=NULL && ptr2!=NULL) {

            if(ptr1->data<ptr2->data) {
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
                ptr3 = ptr3->next;
            }

            else {

                ptr3->next = ptr2;
                ptr2 = ptr2->next;
                ptr3 = ptr3->next;
            } 
        }
 
        if(ptr1) ptr3->next = ptr1;
        else if(ptr2) ptr3->next = ptr2;

        return dummy_head->next;

    }
    
    // to merge k linked list
    Node* mergedKLL(vector<Node*> & list) {                              // list of head nodes

        if(list.size() == 0) return NULL;                                // when list is empty

        while(list.size()>1){                                            // loop till only one left in the node

            Node* new_head = mergeLL(list[0],list[1]);      
            list.push_back(new_head);
            list.erase(list.begin());
            list.erase(list.begin());
        }

        return list[0];                                                // return the last remaining node 
    }

    // to find middle of a linked list
    int middleOfLinkedList(Node* head){

        Node* ptr1 = head;
        Node* ptr2 = head;

        while(ptr2!=NULL && ptr2->next!=NULL){

            ptr2 = ptr2->next->next;                   // fast pointer
            ptr1 = ptr1->next ;                        // slow pointer
        }

        return ptr1->data;
    }

    // to detect cycle in a Linkedlist
    bool detectCycle(Node* head){

        if(head==NULL) return false;

        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                cout << slow->data <<endl;
                return true;
            }
        }

        return false ;
    }

    // to remove the cycle
    void removeCycle(Node* head){

        Node* slow = head;
        Node* fast = head;

         do{                                                       // do while as at first they are pointing to the same
            slow = slow->next;
            fast = fast->next->next;
        }  while(slow!=fast) ;

        fast = head;

        while(fast->next!=slow->next){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL; 

    }

    // to check palindrome or not
    bool isPalindrome(Node* head){

        // 1) to find middle element
        Node* slow =head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }

    // slow is pointing to the middle
    // 2) break the linked list in the middle

        Node* curr = slow->next;
        Node* prev = slow;
        slow->next = NULL;

        // 3) reverse second half of linked list

        while(curr!=NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // prev is pointing to new head
        // 4) Comapare the two linked list

        Node* head1 = head;
        Node* head2 = prev;

        while(head2!=NULL ){

            if(head2->data!=head1->data) return false;

            head2 = head2->next;
            head1 = head1->next;
        }

        return true;
        
    }

    // to rotate the linkedlist by k elements
    Node* rotateByK(Node* &head, int k) {
        
        // 1) calculating length of linkedlist
        int n = 0;

        //2) find tail node
        Node* tail = head;

        while(tail->next!=NULL) {
            n++;
            tail = tail->next;
        }
        n++;
        k = k%n;                                 // if k is greater than n
        if (k==0) return head;

        tail->next = head;   

        //3) traverse n-k nodes
        Node* temp = head;

        for(int i=0;i<n-k;i++){
            temp = temp->next;
        }

        // temp now pointing to (n-k)th node

        Node* new_head = temp->next;
        temp->next = NULL;

        return new_head;

    }
    
    // to segregate even and odd linked list
    Node* oddEvenLinkedList(Node* head){

        if(head==NULL) return head;

        Node* even_head = head->next;
        Node* oddPtr = head;
        Node* evenPtr = even_head;


        while(evenPtr!=NULL && evenPtr->next!=NULL){

            oddPtr->next = oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;
            
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }

        oddPtr->next = even_head;

        return head;
    }

    // to reorder the linked list and print accordingly
    Node* reorderLinkedList(Node* &head){

        //1) finding middle element

        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow is pointing to the middle
        // 2) now separate the linked list and reverse the second half

        Node* prev = slow;
        Node* curr = slow->next;
        slow->next = NULL;

        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        // 3) merging the two halves of the linked list

        Node* ptr1 = head;    // linked list 1
        Node* ptr2 = prev;    // linked list 2

        while(ptr1!=ptr2){
            
            Node* temp = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr2;
            ptr2 = temp;
        }

        return head;
    }


int main(){

    Linkedlist ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    // ll.insertAtTail(1);
    // ll.insertAtTail(8);
    // ll.insertAtTail(3);

    ll.display();

    // alternateDelete(ll.head);
    // sorteddelDuplicates(ll.head);

    // displayrev(ll.head);

    // ll.head = revLinkedList(ll.head);
    // revLinkedList(ll.head);

    // ll.head = revRecurinkedList(ll.head);

    // ll.head = reverseKLL(ll.head,2);

    // ll.display();

    // Linkedlist ll2;
    // ll2.insertAtTail(2);
    // ll2.insertAtTail(3);
    // ll2.insertAtTail(10);
    // ll2.insertAtTail(11);
    // ll2.insertAtTail(342);

    // ll2.display();

    // bool flag =  checkEqualLL(ll.head,ll2.head);
    // if(flag==1) cout << "True" ;
    // else cout << "False";

//    Node* intersection =  getIntersection(ll.head, ll2.head) ;
//     if(intersection) cout << intersection->data;
//     else cout << -1;

// int length = getlength(ll.head);
// cout << length <<endl;

// ll.head = deletefromLast(ll.head,1);

// deletefromLast(ll.head,2);



//    ll2.display();

//    Linkedlist ll3;

//    ll3.head = mergeLL(ll.head,ll2.head);

//    ll3.display();


// int mid = middleOfLinkedList(ll.head);

// cout << mid <<endl;

// int flag = detectCycle(ll.head);

// if(flag==1) cout << "True" <<endl;
// else cout << "False" <<endl;


// ll.head->next->next->next->next->next->next->next->next = ll.head->next->next;

// removeCycle(ll.head);

// ll.display();

// cout << isPalindrome(ll.head) << endl;

// ll.head = rotateByK(ll.head, 3);

ll.head = oddEvenLinkedList(ll.head);

ll.display();

}