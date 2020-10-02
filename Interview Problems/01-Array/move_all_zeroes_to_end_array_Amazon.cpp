#include <bits/stdc++.h> 
using namespace std; 
  
// Function to all zeros to end of an array. 
void pushZerosToEnd(int arr[], int n) 
{ 
    int count = 0;
 
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; 
  
    while (count < n) 
        arr[count++] = 0; 
} 
  
// Driver program
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    
    cout << "Array before pushing all zeros to end of array : "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    
    cout<<"\n";
    pushZerosToEnd(arr, n); 

    cout << "Array after pushing all zeros to end of array : "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 