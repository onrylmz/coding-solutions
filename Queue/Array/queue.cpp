#include <iostream>

using namespace std;

class Queue {
	private:
		int* container;
		int rear;
		int front;
	public:
		Queue();
		void enqueue(int element);
		int dequeue();
		void display();
};

Queue::Queue()
{
	rear = -1;
	front = -1;
}

void Queue::enqueue(int element)
{
	if(container == 0)
	{
		cout << "The size of queue is zero" << endl;
		cout << "Enter a size for queue: ";
		int size;
		cin >> size;
		container = new int[size];
		cout << endl;
	}
	
	if( front == (rear + 1) )
	{
		cout << "Queue is full" << endl;
		return;
	}
	else
	{
		rear++;
		container[rear] = element;
	}
}

int Queue::dequeue()
{
	if(container == 0)
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	
	front++;
	int result = container[front];
	
	return result;
}

void Queue::display()
{
	if(container == 0)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	
	for( int i = front + 1; i <= rear; i++)
	{
		cout << container[i] << " ";
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
	
	return 0;
}
