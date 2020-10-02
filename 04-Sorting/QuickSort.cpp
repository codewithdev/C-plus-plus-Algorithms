#include <iostream>
using namespace std;



int partition(int a[], int f, int l)
{
	int x = a[l];
	int i = (f - 1);
	for (int j = f; j <= l - 1; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	int tmp = a[i + 1];
	a[i + 1] = a[l];
	a[l] = tmp;
	return (i + 1);
}
void quicksort(int a[], int f, int l)
{
	if (f < l)
	{
		int q = partition(a, f, l);
		quicksort(a, f, q - 1);
		quicksort(a, q + 1, l);
	}
}

int main()
{
	int n; //size of array
	cin >> n;
	int *a=new int[n];
	for (int i = 0; i < n; i++) // enter array
	{
		cin >> a[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) // print array
	{
		cout << a[i] << " ";
	}
	cout << endl;
	quicksort(a, 0, n-1); //call quicksort
	for (int i = 0; i < n; i++) //print solution
	{
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
