class Solution {
public:
    int reverse(long long int x) 
{
    long long int b=0,c=0;
    long long int a;
    vector<int> ar;
        if(x<0)
        {
            a=(-x);
        }
        else
        {
            a=x;
        }
        for(int i=1;a>0;i++)
        {
            b=a%10;
            ar.push_back(b);
            a=a/10;
        }
        int k=ar.size();
    for(int j=0;j<k;j++)
    {
       c=c+(ar.at(j)*pow(10,(k-j-1))); 
        
    }
        if(c>=INT_MAX)
        {
            c=0;
        }
        else if(x<0)
        {
            c=(-c);
        }
        else
        {
            c=c;
        }
        return c;
        
}
};
