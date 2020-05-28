#include<iostream>
using namespace std;
class node{
public:
	int data;
    node*next;
    node(int d){
    	data=d;
    	next=NULL;
    }
};
void insert(node*&head,int data){
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
void buildList(node*&head){
	int data;cin>>data;
	while(data!=-1)
	{
       insert(head,data);
       cin>>data;
	}
}
int occurrence(node*&head,int key){
   int count=0;
   while(head!=NULL){
   	if(head->data==key){
   		count++;
   	}
   	head= head->next;
   }
   return count;
}
int main()
{
	node*head= NULL;
	buildList(head);
	int key;cin>>key;
	cout<<occurrence(head,key);
}