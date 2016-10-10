#include <iostream>

using namespace std;

typedef struct Node{
	int data;
	Node* next;
	Node* back;
}Node;

class Queue{
	private:
		Node* front;
		Node* rear;
		
	public:
		Queue();
		void enqueue(int element);
		int dequeue();
		void display();
};

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}


void Queue::enqueue(int element)
{
	Node* ptr = new Node();

	ptr -> data = element;
	
	if(front == NULL && rear == NULL)
	{
		ptr -> next = NULL;
		ptr -> back = NULL;
		
		front = ptr;
		rear = ptr;
		
		return;
	}

	ptr -> back = NULL;	
	ptr -> next = rear;
	
	rear -> back = ptr;
	rear = ptr;
}

int Queue::dequeue()
{
	int result;
	
	if(front == NULL && rear == NULL)
	{
		cout << "Queue is empty!!" << endl;
		return -1;
	}
	
	Node* ptr = front;
	
	result = ptr -> data;
	
	if(ptr == rear)
	{
		ptr = NULL;
		rear = NULL;
		
		delete rear;
	}
	else
	{
		front = front -> back;
	}
	
	delete ptr;
	
	return result;
}

void Queue::display()
{
	if(front == NULL && rear == NULL)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	
	Node* ptr = front;
	
	while(ptr != NULL)
	{
		cout << ptr -> data << " ";
		
		ptr = ptr -> back;
	}
	cout << endl;
}

int main()
{
	Queue q;
	
	q.enqueue(1);
	q.display();
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	
	return 0;
}
