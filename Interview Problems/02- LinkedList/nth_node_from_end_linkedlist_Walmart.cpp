#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n) 
{ 
    int len = 0, i; 
    struct Node* temp = head; 
  
    while (temp != NULL) { 
        temp = temp->next; 
        len++; 
    } 

    if (len < n) 
        return; 
  
    temp = head; 
  
    for (i = 1; i < len - n + 1; i++) 
        temp = temp->next; 
  
    cout << temp->data; 
  
    return; 
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
// Driver Code 
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
    int x, n, N;

    cin>>n>>N;

    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        push(&head, x); 
    }
  
    printNthFromLast(head, N); 
    return 0; 
} 