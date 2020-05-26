#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>v= {10,20,30,40,50,60};

	vector<int>::iterator i= v.begin();    // Use this signature if you want to traverse only the single element.
	cout<<(*i)<<endl;                     // Iterator are treated like Pointer.
    i= next(i,2);
    cout<<(*i)<<endl;
    i= prev(i);
    cout<<(*i)<<endl;


    
}
