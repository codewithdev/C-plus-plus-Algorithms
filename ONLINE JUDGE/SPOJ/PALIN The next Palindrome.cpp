#include<bits/stdc++.h>
using namespace std;

string allnine(string s, int len)
{
    string result(1, '1');
    for(int i=1;i<=len-1;i++)
        result+='0';
    result += '1';
    return result;
}

string findPalindrome(string s, int len)
{
    string left,right,result;
    left = s.substr(0,len/2);
    if(len%2!=0)
        right = s.substr(len/2+1,len/2);
    else
        right = s.substr(len/2,len/2);
    int sublen = left.length();
    for(int i=sublen-1,j=0;i>=0,j<sublen;i--,j++)
    {
        if((left[i]-'0')==(right[j]-'0'))
            continue;
        if((left[i]-'0')>(right[j]-'0'))
        {
            result=left;
            string rev(result.rbegin(),result.rend());
            if(len%2!=0)
                result+= s[len/2];
            result += rev;
            return result;
        }
        if((left[i]-'0')<(right[j]-'0'))
            break;
    }
    int carry=0;
    for(int i=ceil(float(len)/2)-1;i>=0;i--)
    {
        int x = s[i]-'0';
        if(i==(ceil(float(len)/2)-1))
            x=x+1;
        if(carry)
            x = x+carry;
        carry = x/10;
        x=x%10;
        s[i]=x+'0';
        s[len-i-1]=x+'0';
    }
    return s;
}

int main()
{
    long long int t;
    cin>>t;
    string one(1,'1');
    while(t--)
    {
        string str,result;
        cin>>str;
        str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
        int flag=0,len=str.length();
        for(int i=0;i<len;i++)
            if(str[i]!='9')
                flag=1;
        if(flag==0)
        {
            result = allnine(str,len);
            cout<<result<<endl;
            continue;
        }
        result = findPalindrome(str,len);
        cout<<result<<endl;
    }
    return 0;
}