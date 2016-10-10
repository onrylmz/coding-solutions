#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node* next;
}Node;

class Stack {
	private:
		Node* top;
	
	public:
		Stack();
		void push(int element);
		int pop();
		void show();
};

Stack::Stack()
{
	top = NULL;
}

void Stack::push(int element)
{
	Node* ptr = new Node();
	
	ptr -> data = element;
	
	if(top != NULL)
	{
		ptr -> next = top;
	}
	else
	{
		ptr -> next = NULL;
	}
	
	top = ptr;

	return;
}

int Stack::pop()
{
	if(top == NULL)
	{
		cout << "Stack is empty" << endl;
		return -1;
	}	
	
	Node* ptr;
	ptr = top;
	
	top = top -> next;
	
	delete ptr;
	
	return 0;
}

void Stack::show()
{
	if(top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	
	Node* ptr = top;
	
	while( ptr != NULL)
	{
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
	cout << endl;

	return;
}

int main()
{
	Stack s;
	s.push(1);
	s.show();
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.show();
	s.pop();
	s.show();
	s.pop();
	s.show();
	s.pop();
	s.show();
	s.pop();
	s.show();
	
	return 0;
}
