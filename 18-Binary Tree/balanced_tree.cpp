#include<iostream>
using namespace std;
class node{
	public:
	int data;
    node*left;
    node*right;
    node(int data){
    	this->data=data;
    	left=NULL;
    	right=NULL;
    }
};

node*buildTree(){
	int data;cin>>data;
	if(data==-1){
      return NULL;
	}
	node*root= new node(data);
	root->left= buildTree();
	root->right= buildTree();
	return root;
}
void printPreOrder(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

class Pair{
public:
	int height;
	bool balance;
};
Pair isHeightBalanced(node*root){
	Pair p;
	if(root==NULL){
		p.height=0;
		p.balance=true;
		return p;
	}
	Pair left= isHeightBalanced(root->left);
	Pair right= isHeightBalanced(root->right);
	p.height= max(left.height,right.height)+1;
	if(abs(left.height-right.height)<=1 and left.balance and right.balance){
		p.balance=true;
	}
	else{
		p.balance=false;
	}
	return p;
}
int main()
{
	node*root= buildTree();
	if(isHeightBalanced(root).balance){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}