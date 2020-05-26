#include<iostream>
#include<stack>
using namespace std;
void reverse(string &str){
	stack<char>s;
	for(auto ch:str){
		s.push(ch);
	}
	for(int i=0;i<str.length();i++){
		cout<<s.top();
		str[i]=s.pop();
	}
}
int main{()

	string str= "Hello";
	reverse(str);
	cout<<str;
}