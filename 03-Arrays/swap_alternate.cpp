#include <iostream>
using namespace std;

void inputArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
}

void swap(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swapAlternate(int arr[],int size){
    if(size&1){
        for (int i = 0; i < size-2; i+=2)
        {
            swap(arr[i],arr[i+1]);
        }
        
    }
    else{
        for (int i = 0; i < size-1; i+=2)
        {
            swap(arr[i],arr[i+1]);
        }
    }
    
}

void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[100];

    inputArray(arr,n);
    swapAlternate(arr,n);
    printArray(arr,n);
    

    return 0;
}
