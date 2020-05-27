#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*next;
    node(int d){
        data= d;
        next=NULL;
    }
};
int getCount(node*head);
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int data;cin>>data;
        node*head= new node(data);
        node*tail= head;
        for(int i=0;i<n;i++){
            cin>>data;
            tail->next= new node(data);
            tail=tail->next;
        }
        cout<<getCount(head)<<endl;
    }
    return 0;
}
int getCount(node*head){
    int count=0;
    while(head!=NULL){
        count++;
        head= head->next;
    }
    return count;
}