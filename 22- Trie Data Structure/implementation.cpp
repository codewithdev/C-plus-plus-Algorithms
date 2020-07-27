#include<iostream>
#include<unordered_map>
using namespace std;
int main()
class Node{
public:
	char data;
	unordered_map<char,Node*>children;
	bool terminal;

	Node(char d){
		data=d;
		terminal= false;
	}
};

class trie{
	Node *root;
	int count;

public:
	Trie(){
		root= new Node('\0');
		count=0;
	}
	void insert(char *w){
		Node*temp= root;
		for(int i=0;w[i]!='\0';i++){
			char ch= w[i];
			if(temp->children.count(ch)){
				temp= temp->children[ch];
			}
		}
	}
}