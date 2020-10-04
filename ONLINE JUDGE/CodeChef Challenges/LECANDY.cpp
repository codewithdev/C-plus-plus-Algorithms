#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	int i;
	for(i=0;i<T;++i)
	{
	    int N ;
	    long C;
	    cin>>N>>C;
	    long sum=0;
	    int j,k;
	    for(j=0;j<N;++j)
	    {
	        int k;
	        cin>>k;
	        sum+=k;
	        //cout<<endl<<k<<' '<<sum<<endl;
	    }
	    if(sum<=C)
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
