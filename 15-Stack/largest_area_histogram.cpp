#include<iostream>
#include<stack>
using namespace std;
int getmaxArea(int hist[], int n){
	stack<int>s;
	int max=0;
	int tp;
	int area_top;
	int i=0;
	while(i<n){
	if(s.empty() or hist[s.top()]<=hist[i])
		s.push(i++);
	else{
		tp= s.top();
		s.pop();
		area_top= hist[tp]*(s.empty()?i:i-s.top()-1);

		//update max area
		if(max<area_top)
			max= area_top;
	}
}

//Now pop the remaining bars from the stack

	while(s.empty()== false){
		tp= s.top();
		s.pop();
		area_top= hist[tp]*(s.empty()?i:i-s.top()-1);
		if(max<area_top)
			max= area_top;
	}
	return max;	
}



int main()
{
int hist[]= {6,2,5,4,5,1,6};
int n= sizeof(hist)/sizeof(int);
cout<<"Maximum Area is:"<<getmaxArea(hist,n);
}
