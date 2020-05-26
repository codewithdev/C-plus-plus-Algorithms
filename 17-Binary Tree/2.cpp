#include<bits/stdc++.h>
using namespace std;
void findWords(string str,int k){
	string word;
	stringstream ss(str);
	while(ss>>word){
		if(word.size()>k){
			cout<<word<<" ";
		}
	}
}
int main(){
	string str= "Dev Prakash Sharma";
	int k=4;
	findWords(str,k);
}
