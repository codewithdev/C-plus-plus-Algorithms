#include<iostream>
using namespace std;
int main()
{
	int l,i,j;
	cout<<"Enter length of the square matrix (max 100) - \n";
	cin>>l;
	int arr[100][100];
	int tr[100][100];
	cout<<"Enter the matrix row wise - \n";
	for(i=0; i<l; i++)
	{
		for(j=0; j<l; j++)
			cin>>arr[i][j];
	}
	for(i=0; i<l; i++)
	{
		for(j=0; j<l; j++)
			tr[i][j] = arr[j][i];
	}
	cout<<"Transversed array - \n";
	for(i=0; i<l; i++)
	{
		for(j=0; j<l; j++)
			cout<<tr[i][j]<<" ";
		cout<<"\n";	
	}
}
