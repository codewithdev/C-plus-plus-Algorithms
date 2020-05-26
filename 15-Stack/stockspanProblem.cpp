#include<iostream>
#include<stack>
using namespace std;
void printSpan(int a[], int n){
   stack<int>s;
   int ans[100]={0};
   for(int day=0;day<n;day++){
      int currPrice= a[day];
      while(s.empty()== false and a[s.top()]<currPrice){
         s.pop();
      }
      int bd= s.empty()?0:s.top();
      int span= day-bd;
      ans[day]= span;
      s.push(day);
   }
   for(int i=0;i<n;i++){
      cout<<ans[i]<<" ";
   }
}

int main()
{
   int a[]= {100,80,60,30,75,85};
   int n= sizeof(a)/sizeof(int);
   printSpan(a,n);
}