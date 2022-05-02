#include<iostream>
using namespace std;

// Nodes
struct Node{
	// data
	int item;
	// pointer
	Node *next;
	Node(int item){
		this->item = item;
		this->next = NULL;
	}
	~Node(){
		delete next;
	}
}

class LinkedList{
	Node *head, *tail;
public:
	LinkedList(){
		head = tail = NULL;
	}
	~LinkedList(){
	}

	void insertFirst(int item){
		// 1- create new node
		Node* newNode = new Node(item);
		// 2- check if new node is created or not
		if(newNode == NULL){
			cout<<"";
			return;
		}
		// 3- check if linked list is empty or not
		if(head == NULL){
			head = tail = newNode;
			return;
		}
		// 4
		newNode->next = head;
		// 5
		head = newNode;
	}

	void insertLast(int item){
		// 1- create new node
		Node* newNode = new Node(item);
		// 2- check if new node is created or not
		if(newNode == NULL){
			cout<<"";
			return;
		}
		// 3- check if linked list is empty or not
		if(head == NULL){
			head = tail = newNode;
			return;
		}
		// 4
		tail->next = newNode;
		// 5
		tail = newNode;
	}
	
	void insertPosition(int pos,int item){
		if(pos < 0){
			// errr
			// call insert first
			return;
		}
		if(pos == 0){
			insertFirst(item);
			return;
		}
		Node *temp = head;
		for(int i =  0 ; i < pos-1 && temp != NULL; i++)
			temp = temp->next;
		// check if pos not valid
		if(temp == NULL){
			// errr
			// call insert last
			return;
		}
		// create new node
		Node* newNode = new Node(item);
		// 2- check if new node is created or not
		if(newNode == NULL){
			cout<<"";
			return;
		}
		if(temp->next == NULL)
			tail = newNode;
		newNode->next = temp->next;
		temp->next = newNode;
	}
};