/******************************************************************************

program to find sum of all the nodes in a tree.
the program is using level order traversal or BFS.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	struct Node *left, *right;
	Node(int x){
	    data = x;
	    left = right = NULL;
	}
};

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int sum = 0;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
	
		sum += temp->data;

		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
	cout<<sum<<endl;
	return 0;
}

