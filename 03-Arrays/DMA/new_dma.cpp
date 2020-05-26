#include<iostream>
using namespace std;
int main()
{
    int *p= new int(30);
    cout<<*p<<endl;
    int *q= new int();
    cout<<*q<<endl;
    int *arr= new int[30];
    for(int i=0;i<30;i++)
{
    arr[i]=i;
}
for(int i=0;i<30;i++)
{
    cout<<arr[i]<<endl;
}
}