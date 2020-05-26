#include<iostream>
using namespace std;
class node{
   public:
   	int data;
   	node*next;
   	node(int d){
   		data=d;
   		node*next= NULL;
   	}
};
void insertAtFirst(node*&head, int data){
	node*n= new node(data);
	n->next= head;
	head=n;
}
void printNode(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
void deleteatTail(node*head){   //We ware passing only one parameter because we want to delete last node
	node*prev= NULL;      // Hence no need to give int data.
	node*temp= head;      // We are creating a prev node which then get the value of temp until temp reaches to end;
	while(temp->next!=NULL){  // Looping to reach the temp to the end of the linkedList
		prev= temp;       //Updating the value of node*prev
		temp=temp->next;  // Until the loop is running to end in while condition, temp continues to next.
	}
	delete temp;          // deleting the temp.
	prev->next= NULL;      // making the node*prev to last node.
	return;
}
int main()
{
	node*head= NULL;
	insertAtFirst(head,5);
	insertAtFirst(head,4);
	insertAtFirst(head,3);
    insertAtFirst(head,2);
    insertAtFirst(head,1);
    deleteatTail(head);
    printNode(head);
}