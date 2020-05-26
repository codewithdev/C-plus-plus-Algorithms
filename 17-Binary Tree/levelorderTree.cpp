#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int ls= height(root->left);
	int rs= height(root->right);
	return max(ls,rs)+1;
}
void printKthNode(node*root,int K){
	if(root==NULL){
		return;
	}
	if(K==1){
		cout<<root->data<<" ";
		return;
	}
	printKthNode(root->left,K-1);
	printKthNode(root->right,K-1);
    return;
}
void printAllLevels(node*root){
	int h= height(root);
	for(int i=0;i<=h;i++){
		printKthNode(root,i);
	}
}

int main(){ 
    node* root = buildTree();
    print(root);
    cout<<endl;

    printIn(root);
    cout<<endl;
    printPost(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    printKthNode(root,3);
    cout<<endl;
    printAllLevels(root);


return 0;
}










