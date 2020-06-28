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
