#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*next;
	node(int d){                  	//First creating a node class.
		data=d;
		node*next= NULL;
	}
};
void insertAt(node*&head, int data){    // Inserting in the node.
	node*n= new node(data);
	n->next= head;
	head= n;
}
bool searchRecursive(node*head, int key){     //Creating the function which take head and a key which we need to search
  if(head==NULL){   // If head is Null then return false. which is the base case.
  	return false;
  }
if(head->data==key){  //If the current value at the head is equal to key return true.
  return true;
}
else{
	return searchRecursive(head->next, key);   // Else search again which is again check the condition if the data
} 	
}										  // is equal to key or not

// There is another method to searc throughout the linkedlist

bool searchIterative(node*head, int key){
	while(head!=NULL){        // Loop till the head is not equal to NULL
		if(head->data==key){   // if we get the key then return true
			return true;
		}
		head= head->next;    // Else head to next element.
	}
	return false;           // At the end if nothing is found return false.
}

void printNode(node*head){      
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}

int main()
{
	node*head= NULL;
	insertAt(head,5);
	insertAt(head,4);
	insertAt(head,3);
	insertAt(head,2);
	insertAt(head,1);
	printNode(head);
	if(searchRecursive(head,7)){
		cout<<"present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}
	if(searchIterative(head,3)){
		cout<<"present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}
}