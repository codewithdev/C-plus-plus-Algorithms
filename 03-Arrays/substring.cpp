#include<iostream>
using namespace std;
void printsubstr(char *a)
{
    for(int i=0;a[i]!='\0';i++)
    {
        for(int j=i;j<a[j]!='\0';j++)
        {
            cout<<"{"<<i<<","<<j<<"}"<<endl;
        }
    }
}
int main()
{
  char str[4]= "abc";
  printsubstr(str);    
}