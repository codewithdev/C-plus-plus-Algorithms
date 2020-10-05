#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    string name;

public:
    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    string getName() { return name; }
    int getID() { return id; }
};

class FulltimeEmployee : public Employee
{
private:
    int salary;

public:
    FulltimeEmployee(int e, string n, int sal) : Employee(e, n)
    {
        salary = sal;
    }
    int getSalary() { return salary; }
};

class ParttimeEmployee : public Employee
{
private:
    int wage;

public:
    ParttimeEmployee(int e, string n, int w) : Employee(e, n)
    {
        wage = w;
    }
    int getWage() { return wage; }
};

int main()
{
    ParttimeEmployee p1(1, "John", 300);
    FulltimeEmployee p2(2, "Raj", 5000);
    cout << "Salary of " << p2.getName() << " is " << p2.getSalary() << endl;
    cout << "Daily wage of " << p1.getName() << " is " << p1.getWage() << endl;
}