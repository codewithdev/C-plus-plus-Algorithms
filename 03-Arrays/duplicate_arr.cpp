#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);//function to check the duplicates
int main() {
    int t;//number of testcases
    cin >> t;
    while (t-- > 0) {
        int n;//n is lenght of array
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

vector<int> duplicates(int arr[], int n) {
vector<int> v;
    sort(arr,arr+n); //sorting the array
    int i=0;
    int j;
    while(i<n-1){
        j=i+1;
	//if array element and next elements are same then duplicate is present and we push in the vector
        if(arr[j]==arr[i])
            v.push_back(arr[i]);
	//till the array elements are same we don't do anything
        while(arr[i]==arr[j])
            j++;
        i=j;
    }
    //if no duplicate elements are present then outputis -1
    if(v.empty())
        v.push_back(-1);
    return v;
    }



