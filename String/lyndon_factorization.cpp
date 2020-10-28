#include <bits/stdc++.h>

using namespace std;

// Duval algorithm
// Time complexity O(N)
// Memory complexity O(1)
vector<string> duval(string s){
    vector<string>res;

    int n = (int)s.size();
    int i = 0; // s1 => [0...i-1] processed
    int j = 0; // s2 => pre-simple string
    int k = 1; // s3 => [k...n] unprocessed
    while(i < n){
        while (k < n && s[j] <= s[k]){
            if (s[j] == s[k]) j++;
            else j = i; // new simple created
            k++;
        }

        // getting all simple string from s2
        while(i <= j){
            res.push_back(s.substr(i, k-j));
            i += k-j;
        }
        j = i;
        k = i+1;
    }

    return res;
}


int main(){

    string s = "aababbaaab";
    for(string &t:duval(s))
        cout << t << endl;

    return 0;
}
