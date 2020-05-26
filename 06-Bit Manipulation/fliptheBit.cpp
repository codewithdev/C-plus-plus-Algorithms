#include<iostream>
using namespace std;
void toggleBit(int &n){
	n=n&(-n);
}


int main()
{
	int n=40;
    toggleBit(n);
    cout<<n<<endl;
}