#include<iostream>
#define MAX 10 
using namespace std;
class CircularQueue{
	int queue[MAX];
	int front, rear;
public:
	CircularQueue(){
		front = rear = -1;
	}
	void insert(int value){
		if (isFull()){
			cout << "Queue is over flow \n";
			exit(1);
		}
		rear = (rear + 1) % MAX;
		queue[rear] = value;
		if (front == -1)
			front = 0;
	}
	int remove(){
		if (isEmpty()){
			cout << "Queue is under flow \n";
			exit(1);
		}
		int value = queue[front];
		if (front == rear){
			front = rear = -1;
		}
		else
			front = (front+1) % MAX;
		return value;
	}
	int getfront(){
		if (isEmpty()){
			cout << "Queue is under flow \n";
			exit(1);
		}
		return queue[front];
	}
	int getRear(){
		if (isEmpty()){
			cout << "Queue is under flow \n";
			exit(1);
		}
		return queue[rear];
	}
	int size(){
		if (isEmpty())
			return 0;
		if (rear >= front)
			return rear - front + 1;
		else
			return front - rear + 1;
	}
	void display(){
		if (isEmpty()){
			cout << "Queue is Empty\n";
			return;
		}
		// post test
		for (int i = front;; i = (i+1) % MAX){
			cout << queue[i] << "  ";
			if (i == rear)
				break;
		}
		cout << endl;
	}
	bool isEmpty(){
		return front == -1;
	}
	bool isFull(){
		return front == (rear+1)%MAX;
	}
};