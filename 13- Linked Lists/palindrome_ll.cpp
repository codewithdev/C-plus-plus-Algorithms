// in this program we check if the given LL is a palindrome or not and return 1 for Palindrome and 0 for not palindrome
#include <iostream>
#include <stack>
using namespace std;

// linked list structure
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


// function to check given linked list is palindrome or not
bool isPalindrome(Node *head, int n);

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head,n)<<endl;
    }
    return 0;
}


bool isPalindrome(Node *head, int n)
{
    //initialize all the pointers
    Node* temp=head;
    Node* tempcount=head;
    Node* r=head;
    Node* p=NULL;
    Node* q=NULL;
   
    //if only 1 element is present
    if(n==1) 
        return 1;
    
    //if only 2 elements are present
    if(n==2){
        if(temp->data!=temp->next->data)
            return 0;
        else
            return 1;
    }
    
    //for any number of elements present in LL
    int new_count=n/2;
    while(new_count>0){
        r=r->next;
        new_count--;
    }
    
    while(r != NULL){
        p=q;
        q=r;
        r=r->next;
        q->next=p;
    }
    
    int a = n/2;
    while(a>1){
        if(q->data!=temp->data){
            return 0;
            break;
        }
        q=q->next;
        temp=temp->next;
        a--;
    }
    if(q->data==temp->data)
        return 1;
    else
        return 0;
}


