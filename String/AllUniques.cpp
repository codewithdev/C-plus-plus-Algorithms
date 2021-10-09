// An algorithm to check if a string has all unique characters.
// Sample Input-1: Hello
// Sample Output-2: All Characters are not Unique

// Sample Input-1: World
// Sample Output-2: All Characters are Unique


#include<bits/stdc++.h>
using namespace std;

// time complexity = O(n)
// 128-character alphabet set
bool isAllUnique(string st)
{
    if(st.length()>128)
    return false;

    // initialize vector to zero flag
    vector<bool> char_set(128,0);
    int val;
    for (int i = 0; i < st.length(); i++)
    {
        val = st.at(i);
        if(char_set[val])
        {
            // already found this character
            return false;
        }

        char_set[val] = true;
    }
    return true;
}

int main()
{
    string st;
    getline(cin,st);
    if(isAllUnique(st)){
        cout<<"All Characters are Unique"<<endl;
    }else{
        cout<<"All Characters are not Unique"<<endl;
    }
    return 0;
}