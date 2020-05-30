#include<iostream>
#include<cstring>
using namespace std;

long long compute_hash(string s,int p){
	const int m= 1e9 +9;
	long long hash= 0;
	long long pow= 1;
	for(char c:s){
		hash =(hash+(c-'a'+1)*pow)%m;
		pow= (pow*p)%m;
	}
	return hash;
}
int main()
{
	cout<<"Hash of string Programmer is: "<<compute_hash("Programmer",3);
	return 0;
}