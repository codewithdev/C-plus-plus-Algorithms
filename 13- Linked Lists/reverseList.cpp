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
void reverseList(node*&head){
	node*Current=head;
	node*prev=NULL;
	node*n;
	while(Current!=NULL){
		n= Current->next;
		Current->next= prev;
		prev= Current;
		Current=n;
	}
	head=prev;
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head= head->next;
	}
	cout<<endl;
}
int main()
{
	node*head= NULL;
	buildList(head);
    reverseList(head);
    print(head);

}
