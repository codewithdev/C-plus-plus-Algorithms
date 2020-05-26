#include<iostream>
using namespace std;
int  main()
{
	int n;cin>>n;
	int *ptr;
	ptr= new int(n);
    int temp;
	for(int i=0;i<n;i++){
      cin>>temp;
	 *(ptr+i)= temp;
	}
	for(int i=0;i<n;i++){
		cout<<*(ptr+i)<<endl;

	}
	delete ptr;


}