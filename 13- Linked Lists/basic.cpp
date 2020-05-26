#include<iostream>
using namespace std;
class node{
public:
   int data;
   node*next;
   node(int d){
   	data=d;
   	next= NULL;
   }
};

void insertAtNode(node*&head, int data){
	node*n= new node(data);
	n->next=head;
	head=n;
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	node*head=NULL;
	insertAtNode(head,4);
	insertAtNode(head,7);
	insertAtNode(head,9);
	insertAtNode(head,1);
	print(head);
}