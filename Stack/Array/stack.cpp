#include <iostream>

using namespace std;

class Stack {
	private:
		int* container;
		int top;
		int length;
		
	public:
		Stack(int = 0);
		~Stack();
		
		void push(int element);
		int pop();
		void display();
};

Stack::Stack(int size)
{
	this -> top = -1;
	this -> length = size;
	
	if(size == 0)
		container = 0;
	else	
		container = new int[length];
}

Stack::~Stack()
{
	if(container != 0)
		delete [] container;
}

void Stack::push(int element)
{
	if(container == 0)
	{
		cout << "The size of stack is zero" << endl;
		cout << "Enter a size for stack: ";
		cin >> length;
		container = new int[length];
		cout << endl;
	}
	
	if(top == (length - 1) )
	{
		cout << "Cannot push " << element << ", Stack full!!!" << endl;
		return;
	}
	else
	{
		top++;
		container[top] = element;
	}
}

int Stack::pop()
{
	if(container == 0 || top == -1)
	{
		cout << "Stack empty!" << endl;
		return -1;
	}
	
	int result = container[top];
	top--;
	return result;
}

void Stack::display()
{
	for(int i = 0; i <= top; i++)
	{
		cout << container[i] << " ";
	}
	cout << endl;
}

int main()
{
	Stack s1;
	s1.push(1);
	s1.display();
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	
	return 0;
}
