#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main()
{
    Rectangle r1; //here the object is created in stack
    Rectangle *p;
    p = &r1;
    p->length = 5;
    p->breadth = 10;
    cout << p->area() << endl;
    Rectangle *ptr = new Rectangle; //creating an object in heap
    ptr->length = 4;
    ptr->breadth = 1;
    cout << ptr->area() << endl;

    return 0;
}