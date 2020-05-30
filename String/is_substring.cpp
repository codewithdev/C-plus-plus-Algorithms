#include<bits/stdc++.h>
using namespace std;
bool issubstring(string s1,string s2){
	for(int i=0;i<s1.length()-s2.length()+1;i++){
		string x= s1.substr(i,s2.length());
		if(x==s2) return true;
	}
	return false;
}
int main()
{
	string s1= "Genius";
	string s2= "Gen";
	if(issubstring(s1,s2)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}