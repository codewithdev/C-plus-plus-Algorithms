//Tree representation 2
#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
//just one struct that will create Node using constracter function 
struct node{
	int data;
	struct node* left;
	struct node* right;
	node(int data){
			this->data=data;
	left=right=NULL;
	}
};

int max(int x,int y){
	if(x>y)
	return x;
	return y;
}
//Largest sum subtree
int LargestSubtree(struct node* root,int &maxSum){
	if(root==NULL){
		return 0;
	}
	int ls = LargestSubtree(root->left,maxSum);
	int rs = LargestSubtree(root->right,maxSum);
	int whole  = ls + rs + root->data;
	if(whole > maxSum){
		maxSum = whole;
	}
	else if(ls> maxSum){
		maxSum  = ls ;
	}
	else if (rs> maxSum)
		maxSum = rs;
	return  root->data + rs + ls;
}

//just traversal function [utility function]
void printInorder(struct node* root){
	if(root==NULL){
		return ;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}
//driver program
int main(){

/*
            1     
          /   \
        2       3
      /  \     /  \
     4    5    6    7
    / \  / \  / \  / \ 
   8  9 3   1 4  2 7  2
       / \      /   \
     -16 -17   -18  -19
*/
    node* root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7); 
    root->left->left->left = new node(8); 
    root->left->left->right = new node(9); 
    root->left->right->left = new node(3); 
    root->left->right->right = new node(1); 
    root->right->left->left = new node(4); 
    root->right->left->right = new node(2); 
    root->right->right->left = new node(7); 
    root->right->right->right = new node(2); 
    root->left->right->left->left = new node(-16); 
    root->left->right->left->right = new node(-17); 
    root->right->left->right->left = new node(-18); 
    root->right->right->left->right = new node(-19);
	cout<<"Inorder traversal of Binary Tree is  : \n"; 
	printInorder(root);		  	//traversing Tree
	int maxSum =INT_MIN;
	int x = LargestSubtree(root,maxSum);
	cout<<"\nSubtree with Largest Sum : "<<maxSum;
}
