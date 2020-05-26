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
	node*temp=head;
	n->next= head;
	if(head!=NULL){
		while(temp->next!=NULL){
			temp= temp->next;
		}
	}
	else {
			n->next=n;
		}
		head=n;
	}

node* getNode(node*&head, int data){
	node*temp= head;
	while(temp->next!=head){
		if(temp->data==data){

	 return temp;
	}
		temp= temp->next;
	}
	if(temp->data==data) {
		return temp;
}
}
	else return NULL;

void printNode(node*head){
	node*temp=head;
	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp= temp->next;
	}
	cout<<temp->data<<"->";
}
void delNode(node*&head, int data){
	node*del= getNode(head,data);
	if(del==NULL){
		cout<<"Node not present in the LinkedList"<<endl;
	}
	if(head==del){
		head= del->next;
	}
	node*temp= head;
	while(temp->next!=head){
		temp= temp->next;
	}
	temp->next= del->next;
	delete del;
}
int main()
{
	node*head= NULL;
	push(head,10);
	push(head,12);
	push(head,20);
	push(head,30);
	printNode(head);
	delNode(head,20);
	printNode(head);

}
