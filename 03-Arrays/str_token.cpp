#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[1000];
	cin.getline(str,1000);
	char *ptr;
	ptr= strtok(str,"\n");
	while(ptr!=NULL)
	{
		cout<<ptr<<endl;
		ptr= strtok(NULL," ");
	}
	return 0;
}
