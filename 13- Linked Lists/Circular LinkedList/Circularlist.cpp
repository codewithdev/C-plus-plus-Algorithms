#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*next;
	node(int data){
		this->data= data;
		node*next= NULL;
	}
};
void push(node*&head, int data){
	node*n= new node(data);
	node*temp= head;
	n->next= head;
	if(head!=NULL){
		while(temp->next!=head){
			temp= temp->next;
		}
		temp->next=n;
	}
	else{
		n->next= n;
	}
	head=n;
}

void printNode(node*head){
	node*temp= head;
	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp= temp->next;
	}
	cout<<temp->data<<"->";
}
int main()
{
	node*head= NULL;
	push(head,10);
	push(head,4);
	push(head,3);
	push(head,2);
	printNode(head);

}