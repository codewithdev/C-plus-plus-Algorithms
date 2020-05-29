#include<bits/stdc++.h>
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
	int d;cin>>d;
	if(d==-1){
		return NULL;
	}
	node*root= new node(d);
	root->left= buildTree();
	root->right= buildTree();
	return root;
}
void printnodePre(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printnodePre(root->left);
	printnodePre(root->right);
}
void bfs(node*root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*f= q.front();
        cout<<f->data<<" ";
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}
int replaceSum(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	// Here is the recursive Part
	int lsum= replaceSum(root->left);
	int rsum= replaceSum(root->right);
	int sum= root->data;
	root->data= lsum+rsum;
	return sum+ root->data;
}
int main(){
	node*root= buildTree();
	bfs(root);
	cout<<endl;
	replaceSum(root);
	bfs(root);
	return 0;
}

