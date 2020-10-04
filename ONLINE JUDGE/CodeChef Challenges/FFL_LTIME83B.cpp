#include <iostream>
using namespace std;

int main() {
	int T,N,S,minz,mino;
	cin>>T;
	
	while(T--)
	{
	    minz=100;
	    mino=100;
	    cin>>N>>S;
	    int A1[N],A2[N];
	    for(int i=0;i<N;++i)
	        cin>>A1[i];
	   for(int i=0;i<N;++i)
	        cin>>A2[i];
	   for(int i=0;i<N;i++)
	   {
	       if(A2[i]==0)
	       {
	           minz=minz<A1[i]?minz:A1[i];
	       }
	       if(A2[i]==1)
	       {
	           mino=mino<A1[i]?mino:A1[i];
	       }
	   }
	   if((S+minz+mino)<=100)
	        cout<<"yes"<<endl;
	   else
	    cout<<"no"<<endl;
	}
	return 0;
}
