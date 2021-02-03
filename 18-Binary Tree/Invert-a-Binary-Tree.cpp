

/*Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/



#include<iostream>
using namespace std;
struct treenode{
 int data;
 treenode*left;
 treenode*right;
};

struct treenode* createNode(int d){
    struct treenode*root= new treenode;
    root->data= d;
    root->left= NULL;
    root->right= NULL;
    return root;    
}

void flipNodes(treenode*root){
    if(root==NULL){
        return;
    }
   treenode*temp= root->left;
   root->left= root->right;
   root->right= temp;
}
treenode*invertBinaryTree(treenode*root){
    flipNodes(root);
    return root;
}

int heightofTree(treenode*root){
    if(root==NULL){
        return 0;
    }
    return max(heightofTree(root->left), heightofTree(root->right))+1;
}

void givenlevel(treenode*root, int lev){
    if(root==NULL){
        return;
    }
    if(lev==1){
        cout<<root->data<<" ";
    }
    else if(lev>1){
        givenlevel(root->left,lev-1);
        givenlevel(root->right,lev-1);
    }
}

void printLevelwise(treenode*root){
    int height= heightofTree(root);
    int i;
    for(i=1;i<=height;i++){
        givenlevel(root,i);
   }
}

int main(){
struct treenode*root= NULL;
root= createNode(4);
root->left= createNode(2);
root->right= createNode(7);
root->left->right= createNode(3);
root->left->left= createNode(1);
root->right->left= createNode(6);
root->right->right= createNode(9);
printLevelwise(root);
cout<<endl;
invertBinaryTree(root);
printLevelwise(root);

return 0;
}
