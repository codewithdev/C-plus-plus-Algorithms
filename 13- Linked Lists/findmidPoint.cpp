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
void insertAtBeginning(node*&head, int data){
	node*n= new node(data);
	n->next= head;
	head=n;
}
void printNode(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head= head->next;
	}
}
node*middle(node*head){
	if(head->next==NULL and head==NULL){
		return head;
	}
	else{
		node*slow;
		node*fast;
		while(fast->next!=NULL and fast!=NULL){
		 fast= head->next->next;
		 slow= head->next;
		}
	return slow;
	}
	
}
	
int main()
{
	node*head=NULL;
	insertAtBeginning(head,4);
	insertAtBeginning(head,3);
	insertAtBeginning(head,2);
	insertAtBeginning(head,1);
	insertAtBeginning(head,8);
	printNode(head);
	cout<<endl;
	node*m= middle(head);
	cout<<m->data<<endl;
	return 0;

}