#include <iostream>
using namespace std;
class node{                 // For the construction of One Node we have created the dataType of Node
    public:                 // default is private hence we created it Public
    int data;               // A single node contains a int data and node*next which contains the address of next node.
    node*next;

    node(int d){            // Constructor for node Function
        data=d;
        next=NULL;          // next pointer can be NULL always.
    }
};
int main() {
    cout<<"Hello World!";
}
