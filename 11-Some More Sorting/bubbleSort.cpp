//Worst case time complexity: array is in decending order- log(n^2)

#include <iostream>
using namespace std;

int BubbleSort( int A [20], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    for (j = 0; j < n-1; j++)
    {
      if (A [j] > A [j+1])
      {
        temp = A [j];
        A [j] = A [j + 1];
        A [j + 1] = temp;
      }
    }
  }
  cout << "The sorted array is: ";
  for (i = 0; i < n; i++)
  {
    cout << A [i] <<" ";
  }
}

int main ()
{
  int A [20], i, n;
  cout << "Enter the number of total elements of array:";
  cin >> n;
  cout << "\nEnter the array elements:\n";
  for (i =0; i < n; i ++)
  {
    cin >> A [i];
  }
  cout << endl;
  
  BubbleSort( A, n );
  return 0;
}
