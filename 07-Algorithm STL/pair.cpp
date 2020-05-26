#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    pair<int,string> p= make_pair(100,"Audi");
    cout<<p.first<<endl;
    cout<<p.second<<endl;

//second way;

pair<int,string>p2;
p2.first= 200;
p2.second="Buggatti";
cout<<p2.first<<" "<<p2.second<<endl;

//Taking input;

int n;cin>>n;
string s;
getline(cin,s);
pair<int, string> p3= make_pair(n,s);
cout<<p3.first<< "," <<p3.second<<endl;
}