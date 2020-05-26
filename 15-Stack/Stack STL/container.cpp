#include<bits/stdc++.h>
using namespace std;
void printStack(pair<int,int>s){
	cout<<"("<<s.first<<","<<s.second<<")"<<endl;
}
void showStack(stack<pair<int,int>>p){
	while(!p.empty()){
		printStack(p.top());
		p.pop();
	}
}

int main()
{
	stack<pair<int,int>>s;
	s.push({10,20});
	s.push({20,30});
	s.push({30,40});
	s.push({40,50});
	s.push({50,60});
	cout<<"Showing stack"<<endl;
	showStack(s);


}