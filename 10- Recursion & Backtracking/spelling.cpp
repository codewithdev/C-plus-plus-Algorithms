#include<iostream>
using namespace std;
char spelling[][10]= {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
void print(int n){
if(n==0){
	return;
}
print(n/10);
cout<<spelling[n%10]<<" ";
}

int main()
{
	int n;cin>>n;
	print(n);
}