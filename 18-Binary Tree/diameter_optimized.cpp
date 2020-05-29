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
class Pair{
public:
	int height;
	int diameter;
};

Pair optDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.diameter= p.height=0;
		return p;
	}
	Pair left= optDiameter(root->left);
	Pair right= optDiameter(root->right);	
	p.height= max(left.height,right.height)+1;
	p.diameter= max(left.height+right.height,max(left.diameter,right.diameter));
	return p;
}

int main()
{
	node*root= buildTree();
	cout<<height(root)<<endl;
	Pair p= optDiameter(root);
	cout<<p.height<<endl;
	cout<<p.diameter<<endl;
}