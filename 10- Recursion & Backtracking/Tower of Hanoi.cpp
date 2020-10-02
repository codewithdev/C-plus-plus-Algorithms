// This Algorithm will Print the steps to 
// solve the Tower of Hanoi problem
// using Recursion and Backtracking.

#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(string src, string des, string help, int n) {
	if (n == 0)
		return;

	// PHASE 1: Move n-1 disc from src to help
	// using des.
	TowerOfHanoi(src, help, des, n - 1);
	// Moving the main base disc
	cout << "Move disc " << n << " from " << src << " " << help << "\n";
	// PHASE 2: Move n-1 disc from help to des
	// using src.
	TowerOfHanoi(help, des, src, n - 1);
}

int main() {
    string source = "SOURCE", 
    destination = "DESTINATION", 
    helper = "HELPER";
    int n = 3;
    TowerOfHanoi(source, destination, helper, n);
}