/*When we insert the Key-value Pair the Table Size increases as well as load Factor increases. 
When the load factor> 0.75 means when the 75% of the table is filled then rehashing process done. */


#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node<T>*next;
	Node(string key, T val){
		this->key= key;
		value= val;
		next= NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};
template<typename T>
class Hashtable{
	Node<T>**table; //pointer to an array of an pointers

	int current_size;
	int table_size;
	int hashfun(string key){
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++){
			idx= idx+(key[j]*p)%table_size;
			idx= idx%table_size;
			p= (p*27)%table_size;
		}
		return idx;
	}
	void rehashing(){
		Node<T>**oldtable=table;
		int oldsize= table_size;
		table_size= 2*table_size; //
		table= new Node<T>*[table_size];
		for(int i=0;i<table_size;i++){
			table[i]=NULL;
		}
		current_size=0;
		//Shift the table from old table to new table;

		for(int i=0;i<oldsize;i++){
			Node<T>*temp= oldtable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp= temp->next;
			}
			// Delete entire row in old table
			if(oldtable[i]!=NULL){
				delete oldtable[i];
				// Recursively destructive class.
			}
		}
		delete [] oldtable;	
	}

public:
	Hashtable(int ts=7){
		table_size=ts;
		table= new Node<T>*[table_size];
		current_size=0;
		for(int i=0;i<table_size;i++){
			table[i]=NULL;
		}
	}
	void insert(string key, T value){
		int idx= hashfun(key);
		Node<T>*n= new Node<T>(key,value);
		n->next= table[idx];
		table[idx]=n;
		current_size++;

		float load_factor= current_size/(1.0*table_size);
		if(load_factor>0.7){
			rehashing();
		}
	}
	void print(){
		for(int i=0;i<table_size;i++){
			cout<<"Bucket is "<<i<<"-->";
			Node<T>*temp= table[i];
			while(temp!=NULL){
				cout<<temp->key<<"-->";
				temp= temp->next;
			}
			cout<<endl;
		}
	}
};
