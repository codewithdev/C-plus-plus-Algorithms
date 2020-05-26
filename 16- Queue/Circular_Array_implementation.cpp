#include<bits/stdc++.h>
using namespace std;
class Queue{
	int *arr;
	int ms;
	int cs;
	int front;
	int rear;

public:
	Queue(int default_size=7){
		this->front=0;
		this->rear= default_size-1;
		this->ms= default_size;
		this->arr= new int[this->ms];

	}
		bool isFull(){
		 return	this->cs= this->ms;
		}

		bool isEmpty(){
		return this->cs==0;

		}
		void enqueue(int data){
         while(!isFull()){
         	this->rear= (this->rear+1)%this->ms;
         	this->arr[this->rear]=data;
         	this->cs+=1;
         }
		}
		void deque(){
			while(!isEmpty()){
				this->front= (this->front+1)%this->ms;
				this->cs-=1;
			}
		}
		int getFront(){
			return this->arr[this->front];

		}
};

int main(int argc, char const *argv[]){
	Queue q(10);
	for(int i=0;i<=5;i++){
		q.enqueue(i);
	}
	q.deque();
	q.enqueue(8);
	while(!q.isEmpty()){
		cout<<q.getFront()<<endl;
		q.deque();
	}
	return 0;
}


