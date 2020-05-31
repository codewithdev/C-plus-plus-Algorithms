#include<iostream>
using namespace std;
class node{
  public:
  	int data;
  	node*left;
  	node*right;
  	node(int d): data(d),left(NULL),right(NULL){}
};

class Custom {
public:
	bool haskey1;
	bool haskey2;
	node*root;
};

Custom* helper(node*root,node*p,node*q)
{
	if(root==NULL) return NULL;
	Custom*leftans= helper(root->left,p,q);
	if(leftans!=NULL and leftans->node!=NULL){
		return leftans;
	}
	Custom *rightans= helper(root->right,p,q);
	if(rightans!=NULL and rightans->node!=NULL){
		return rightans;
	}
	Custom *res= new Custom();
	if(leftans!=NULL and rightans!=NULL){
		res->node= root;
		res->haskey1=true;
		res->haskey2=true;
		return res;
	}
	else if(root->val==p->val){
		res->haskey1=true;
		res->haskey2= (leftans)?leftans->haskey2:false or (rightans)?rightans->haskey2:false;
		if(res->haskey1==true and res->haskey2==true){
			res->node= root;
			return res;
		}
		else if(root->val==q->val){
		res->haskey2=true;
		res->haskey1= (leftans)?leftans->haskey1:false or (rightans)?rightans->haskey1:false;
		if(res->haskey1==true and res->haskey2==true){
			res->node= root;
			return res;
	}
	else if(leftans){
		return leftans;
	}
	else if(rightans){
		 return rightans;
	}
	return NULL;

}
node*lowestcommanancestor(node*root, node*p, node*q){
	Custom*result= helper(root,p,q);
	if(result==NULL){
		return NULL;
	}
	else{
		return result->node;
	}
}