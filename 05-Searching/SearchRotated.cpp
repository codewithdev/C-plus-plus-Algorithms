#include<iostream>
using namespace std;
int SearchIn(int a[], int s, int e, int key){
 //Base Search

 if(s>e){
     return -1;
 }
 //Rec Case
int mid= (s+e)/2;
if(a[mid]==key){
    return mid;
}
//Mid lies in the first line
while(a[s]<=a[mid]){
    if(key<=a[mid] && key>=a[s]){
        return SearchIn(a,s,mid-1,key);
    }
    else{
        return SearchIn(a,mid+1,e,key);
    }
}
//Mid lies in the second part
if(key>=a[mid] && key<=a[e]){
    return SearchIn(a,mid+1,e,key);
}
  return SearchIn(a,s,mid-1,key);
}
int main()
{
    int a[]= {7,8,1,2,3,4,5,6};
    int key;cin>>key;
    cout<<key<<"is present at "<<SearchIn(a,0,8,key);
}

