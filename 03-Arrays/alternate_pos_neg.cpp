/*Problem Statement

Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.*/

#include<bits/stdc++.h>
using namespace std;
void rearrange(int *arr, int n){
   vector<int>pos,neg;
   for(int i=0;i<n;i++){
      if(arr[i]<0)
      neg.push_back(arr[i]);
      else
      pos.push_back(arr[i]);
   }

   int i=0, j=0,k=0;
   while(i<pos.size() and j<neg.size())
   {
      arr[k++]= pos[i++];
      arr[k++]= neg[j++];
   }
   while(i<pos.size())
   {
      arr[k++]= pos[i++];
   }
   while(j<neg.size())
   {
      arr[k++]= neg[j++];
   }

}


int main(){
  int n;
  cin>>n;
  int *arr= new int[n];
  for(int i=0;i<n;i++){
   cin>>arr[i];
  }
  rearrange(arr,n);
  for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
  }
}
