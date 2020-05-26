#include<iostream>
using namespace std;
void increment(int *aptr)
{
   *aptr= *aptr+1;
   cout<<"Inside Function:"<<*aptr<<endl;
}
int main()
{
   int a= 5;
   increment(&a);
   cout<<a<<endl;
}