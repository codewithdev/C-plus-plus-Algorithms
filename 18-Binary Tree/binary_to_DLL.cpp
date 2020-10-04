
// } Driver Code Ends


/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should convert a given Binary tree to Doubly
// Linked List

void bToDLL(Node *root, Node **head)
{
    if(root==NULL)
        return;
    static Node* prev=NULL;
    bToDLL(root->left,head);
    if(*head==NULL)
    {
        prev=NULL;
        *head=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    bToDLL(root->right,head);
}

