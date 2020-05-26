#include<iostream>
using namespace std;

class Car{
public:
	int price;
	int model_no;
	char str;
};

void start(){
	cout<<"Grr....."<<endl;
}

int main()
{
	Car c;
	c.price=300;
	c.model_no=2001;
	c.str("BMW");
	c.start();
	cout<<c.price<<c.model_no<<c.str<<endl;
}