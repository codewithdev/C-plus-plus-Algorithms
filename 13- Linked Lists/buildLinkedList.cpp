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
	head= n;
}
void printNode(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head= head->next;
	}
	cout<<endl;
}
void inserAtTail(node*&head, int data){
	if(head==NULL){
		head= new node(data);
		return;
	}
	else{
		node*tail= head;
		while(tail->next!=NULL){
			tail= tail->next;
		}
		return;
	}
}
void buildList(node*&head ){
	int data;cin>>data;
	while(data!=-1){
		inserAtTail(head,data);
		cin>>data;
	}
}
int main()
{
	node*head= NULL;
    buildList(head);
    printNode(head);

}