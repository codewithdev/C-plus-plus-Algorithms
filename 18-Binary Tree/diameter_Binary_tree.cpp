// The Diameter of the binary tree is nothing but the maximum height of the left or right subtree
// Case1. Sum of height of two subtree(left subtree +right Subtree)
// Case2. Diameter of the Left Subtree.
// Case3. Diameter of the right Subtree.
// Maximum of (Case1, Case2, Case3)


#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node*buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node*root= new node(d);
	root->left= buildTree();
	root->right= buildTree();
	return root;
}
void printNodeInorder(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printNodeInorder(root->left);
	printNodeInorder(root->right);
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int ls= height(root->left);
	int rs= height(root->right);
	return max(ls,rs)+1;
}
int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int h1= height(root->left);
	int h2= height(root->right);
	int op1= h1+h2;
	int op2= diameter(root->left);
	int op3= diameter(root->right);
	return max(op1,max(op2,op3));
}
int main()
{
	node*root= buildTree();
	cout<<height(root)<<endl;
	cout<<diameter(root)<<endl;
}