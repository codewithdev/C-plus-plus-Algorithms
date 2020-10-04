#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bucket_sort(float arr[], int n) {

    vector<float> bucket[n];

    // Putting the array elements in different buckets...
    for(int i = 0; i<n; i++)  {  
      bucket[int(n*arr[i])].push_back(arr[i]);
    }

    // Sorting each individual vectors...
    for(int i = 0; i<n; i++) {
      sort(bucket[i].begin(), bucket[i].end());       
    }

    int index = 0;
    for(int i = 0; i<n; i++) {

      while(!bucket[i].empty()) {
         arr[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
    }
}
int main() {
   int n = 5; // Number of elements in the array...

   // Elements of the array..
   float arr[] = {0.5,0.3,0.2,0.1,0.4};    
   
   bucket_sort(arr, n);

   // Printing the array after sorting using bucket sort...
   for(int i = 0; i<n; i++){
       cout<<arr[i]<<" ";
   }
   cout<<"\n";
   return 0;
}