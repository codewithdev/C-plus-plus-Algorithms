#include<iostream>
#include<stack>
using namespace std;
bool charExpression(string str){
	stack<string>str;
	for(int i=0;i<str.size();i++){
		char exp= str[i];
		if(exp=='('){
			str.push(exp);
		}
		else if(str.empty() or !str.top()='('){
			return false;
		}
		str.pop();
	}	
}
return str.empty();

int main()
{
	string str;
	cin>>str;
	bool isValid= char charExpression(str);
	cout<<isValid;
}