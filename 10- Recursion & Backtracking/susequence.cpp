#include<iostream>
using namespace std;
char subsequence(char *in, char *out, int i, int j ){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<","<<endl;
return;
	}
	out[j]=in[i];
	subsequence(in,out,i+1,j+1);
	subsequence(in,out,i+1,j);

}

int main()
{
	char in[100];
	cin>>in;
	cin.ignore();
	char out[100];
	subsequence(in,out,0,0);
	subsequence(in,out,0,0);
}