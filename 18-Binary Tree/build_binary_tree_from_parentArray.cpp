//build binary tree from parent array

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* makeTree(vector<int> a,int i,int n){
	if(i<n){
		if(a[i]==-1)
			return NULL;
		struct node* root = (node*)malloc(sizeof(node));
		root->data=a[i];
		root->left=makeTree(a,2*i+1,n);
		root->right=makeTree(a,2*i+2,n);
		return root;	
	}
	return NULL;
}
void inorder(struct node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}
int main(){
	int n;
	cin>>n;
	//1 2 3 -1 -1 4 5 -1 -1 -1 -1 6 7  [parent array]
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	struct node* root = makeTree(a,0,n);
	inorder(root);
	
}

