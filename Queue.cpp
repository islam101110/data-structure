#include<iostream>
#define MAX 10 
using namespace std;
class FixedQueue{
private:
	int queue[MAX];
	int front, rear;
public:
	FixedQueue(){
		front = rear = -1;
	}
	void insert(int value){
		if (isFull()){
			cout<<"Queue is over flow \n";
			exit(1);
		}
		queue[++rear] = value;
		if (front == -1)
			front = 0;
	}
	int remove(){
		if (isEmpty()){
			cout<<"Queue is under flow \n";
			exit(1);
		}
		int value = queue[front];
		if (front == rear){
			front = rear = -1;
		}
		else
			front++;
		return value;
	}
	int getfront(){
		if (isEmpty()){
			cout<<"Queue is under flow \n";
			exit(1);
		}
		return queue[front];
	}
	int getRear(){
		if (isEmpty()){
			cout<<"Queue is under flow \n";
			exit(1);
		}
		return queue[rear];
	}
	int size(){
		return isEmpty() ? 0 : rear - front + 1;
	}
	void display(){
		if (isEmpty()){
			cout << "Queue is Empty\n";
			return;
		}
		for (int i = front; i <= rear; i++){
			cout << queue[i] << "  ";
		}
		cout << endl;
	}
	bool isEmpty(){
		return front == -1;
	}
	bool isFull(){
		return rear == MAX - 1;
	}
};

void main(){
	FixedQueue queue;
	cout<<queue.size()<<endl;
	queue.insert(10);
	queue.insert(3);
	queue.insert(0);
	queue.insert(5);
	cout << queue.size() << endl;
	queue.display();
	queue.remove();
	cout << queue.size() << endl;
	queue.display();
	cout << endl;
	system("pause");
}