#include<iostream>
using namespace std;
int clearLastbit(int n, int i){
    int mask= (-1<<i);  // int mask= ~(0)<<i
    return n&mask;
}
int main()
{
   int n=15;
   int i=2;
   cout<<clearLastbit(n,i)<<endl;   
}
