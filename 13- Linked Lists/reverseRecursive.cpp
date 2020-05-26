#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*next;
	node(int d){
		data=d;
		node*next=NULL;
	}
};
void insertatHead(node*head,int data){
	node*n= new node(data);
	n->next= head;
	head= n;
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head= head->next;
	}
	cout<<endl;
}
node*reverseRecursive(node*head){
	if(head->next==NULL || head==NULL){
		return head;
	}
	else{
		node*smallhead= reverseRecursive(head->next);
		node*c= head;
		c->next->next= c;
		c->next= NULL;
		return smallhead;
	}
}
int main()
{
	node*head=NULL;
	insertatHead(head,4);
	insertatHead(head,1);
	insertatHead(head,2);
	reverseRecursive(head);
	print(head);
}