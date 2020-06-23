#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Person{
public:
	string name;
	int age;
	Person(string n, int a){
		name=n;
		age=a;
	}
};
class PersonCompare{
public: 
	bool operator()(Person A, Person B){
		return A.age<B.age;
	}
};

int main(){
    int n;
    cin>>n;
    priority_queue<Person,vector<int>,PersonCompare>pq;
    for(int i=0;i<n;i++){
    	string name;
    	int age;
    	cin>>name>>age;
    	Person p(name,age);
        pq.push(p);
    }
    return 0;

}