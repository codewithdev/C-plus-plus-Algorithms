// Simple C++ program to find the pair with sum closest to a given no. k
#include <bits/stdc++.h>
using namespace std;

// Prints the pair with sum closest to k
void printClosest(int arr[], int n, int k)
{
	int res_l, res_r; // To store indexes of result pair

	// Initialize left and right indexes and difference between
	// pair sum and k
	int l = 0, r = n-1, diff = INT_MAX;

	// While there are elements between l and r
	while (r > l)
	{
	// Check if this pair is closer than the closest pair so far
	if (abs(arr[l] + arr[r] - k) < diff)
	{
		res_l = l;
		res_r = r;
		diff = abs(arr[l] + arr[r] - k);
	}

	// If this pair has more sum, move to smaller values.
	if (arr[l] + arr[r] > k)
		r--;
	else // Move to larger values
		l++;
	}

	cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r];
}

// Driver program to test above functions
int main()
{
	int arr[] = {10, 28, 22, 40, 30, 29}, k = 54;
	int n = sizeof(arr)/sizeof(arr[0]);
  //sort the given array
  sort(arr,arr+n);
	printClosest(arr, n, k);
	return 0;
}
