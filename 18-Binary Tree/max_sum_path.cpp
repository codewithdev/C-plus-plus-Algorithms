#include<iostream>
using namespace std;
class node {
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data=d;
		left=NULL;
	    right= NULL;
	}
};
node *buildTree(){
	int d;cin>>d;
    if(d==-1){
    	return NULL;
    }
    node*root= new node(d);
    root->left= buildTree();
    root->right= buildTree();
    return root;
}
void printIn(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printIn(root->left);
	printIn(root->right);
}
class Solution{
public:
	int global_max=0;
	int maxSumPath(node* root){
    if(root==NULL){
    	return 0;
    }
    int ls= maxSumPath(root->left);
    int rs= maxSumPath(root->right);
    int c1= root->data;
    int c2= ls+ root->data;
    int c3= rs+ root->data;
    int c4= ls+rs+root->data;
    global_max= max(c1,max(c2,max(c3,max(c4,global_max))));
    return max(c1,max(rs,0))+ root->data;
}
};

int main(int argc, char const *argv[])
{
   node*root= buildTree();
   printIn(root);
   Solution s1;
   s1.maxSumPath(root);
   
}