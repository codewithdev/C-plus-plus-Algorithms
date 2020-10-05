#include <iostream>

using namespace std;
/*
We dont usually write funtions in the class 
We write outside using scape resolution operator ::


*/
class Rectangle
{   
    private:
    int length;
    int breadth;
    public:
    Rectangle();
    Rectangle(int l,int b);
    Rectangle(Rectangle &r);
    int getLength(){return length;}
    int getBreadth(){return breadth;}
    void setLength(int l);
    void setBreadth(int b);
    int area();
    int perimeter();
    bool isSquare();
    ~Rectangle();
};

int main()
{
    Rectangle r1(10,10);
    cout<<"Area "<<r1.area()<<endl;
    if(r1.isSquare())
    cout<<"Yes"<<endl;
}

Rectangle::Rectangle(int length=1,int breadth=1)
{
    this->length=length;//this is used to access the members of the class
    this->breadth=breadth;
}

Rectangle::Rectangle(Rectangle &r)
{
    length=r.length;
    breadth=r.breadth;
}

void Rectangle::setLength(int l) {if(l>0) length=l;}

void Rectangle::setBreadth(int b){if(b>0) breadth=b;}

int Rectangle::area(){ return length*breadth;}

int Rectangle::perimeter(){return 2*(length+breadth);}

bool Rectangle::isSquare(){return length==breadth;}

Rectangle::~Rectangle(){ cout<<"Rectangle Destroyed"<<endl;}
