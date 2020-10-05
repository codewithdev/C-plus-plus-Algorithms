#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v{1, 2, 3, 4, 5, 14};
	vector<int>::iterator it;
	// Delete last element
	it = v.end()-1;
	v.erase(it);
	for (int x:v) {
		cout<<x<< ",";
	}
}