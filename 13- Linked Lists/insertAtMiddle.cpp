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
int length(node*head){
	int len=0;
	while(head!=NULL){
		len+=1;
	}
	return len;
}
void insertAtTail(node*&head,int data){
	if(head=NULL){
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
void insertAtFirst(node*&head, int data){
	node*n = new node(data);
	n->next= head;
	head=n;
}
void insertAtMiddle(node*&head, int data, int p){
	if(head==NULL or p==0){           //Why Not to create a function for this which would be very easy to insert
	   insertAtFirst(head,data);      //at the first node. :D 		
	}
	//If Postition is given which is higher than the length of the LinkedList we will insert into the end. Obviously.:)
	else if(p>length(head)){
		insertAtTail(head, data);
	}
	//Insert at the Middle.
	else{
		//First we need to compute from the Jump 1 to Jump P-1.
		//Because if our position=3 then we need to insert this element after 2nd node.
       int jump=1;
       node*temp=head;
       while(jump<=p-1){
       	 temp= temp->next;
       	 jump+=1;
       }
       // Now after loop is end temp is at right position
       //We will create a new Node which contains the new element we want to insert 
       // And since every node contains a int data + next node so the node* of this newly created node will
       // point to the temp*next node which was pointing earlier. Its simple.
       node*n= new node(data);
       temp->next= n;
       n->next= temp->next;
       }
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
   insertAtFirst(head,1);
   insertAtFirst(head,2);
   insertAtTail(head,4);
   insertAtMiddle(head,3,2);
   print(head);
}
