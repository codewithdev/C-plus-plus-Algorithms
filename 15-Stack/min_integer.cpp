#include<bits/stdc++.h>
using namespace std;
int getMinNo(int n){
	stack<int>s1;
	stack<int>s2;
	int ans=0;
	while(n!=0){
      int r= n%10;
      if(r%2==0){
      	s1.push(r);
      }
      else{
      	s2.push(r);
      }
      n/=10;
	}
	while(!s1.empty() and !s2.empty()){
		if(s1.top()<s2.top()){
			ans= ans*10+s1.top();
		    s1.pop();
		}
		else{
			ans= ans*10+s2.top();
			s2.pop();
		}
	}
	while(!s1.empty()){
	if(s1.top()<s2.top()){
			ans= ans*10+s1.top();	
			s1.pop();
	}
	while(!s2.empty()){
		ans= ans*10+s2.top();
		s2.pop();
	}
}
	return ans;

}


int main()
{
	int n1= 64432;
	cout<<getMinNo(n1)<<endl;
	int n2= 3221;
	cout<<getMinNo(n2)<<endl;
}