#include<bits/stdc++.h>
using namespace std;

string findDiff(string str1, string str2) 
{ 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2;  
    int carry = 0; 
  
    for (int i=n2-1; i>=0; i--) 
    { 
        int sub = ((str1[i+diff]-'0') - (str2[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0)
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
    reverse(str.begin(), str.end()); 
    return str; 
} 
 
string findSum(string str1, string str2) 
{ 
    string str = ""; 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    int n1 = str1.length(), n2 = str2.length(); 

    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
 
    reverse(str.begin(), str.end()); 
  
    return str; 
}
string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
  
    while (number.size() > idx) { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
}
int main()
{
    int t=10;
    while(t--)
    {
        string a,b,x,y;
        cin>>a>>b;
        x=findSum(a,b);
        y=findDiff(a,b);
        cout<<longDivision(x,2)<<endl<<longDivision(y,2)<<endl;
    }
    return 0;
}