#include <iostream>

using namespace std;

typedef struct tNode
{
	int data;
	tNode* left;
	tNode* right;
}tNode;

typedef struct Node
{
	tNode* data;
	Node* next;
}Node;


class Stack {
	private:
		Node* top;
	
	public:
		Stack();
		void push(tNode* element);
		tNode* pop();
		void show();
		bool isEmpty();
};

Stack::Stack()
{
	top = NULL;
}

void Stack::push(tNode* element)
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

tNode* Stack::pop()
{
	if(top == NULL)
	{
		cout << "Stack is empty" << endl;
		return 0;
	}	
	
	Node* ptr;
	ptr = top;
	
	top = top -> next;
	
	return ptr -> data;
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
		cout << ptr -> data -> data << " ";
		ptr = ptr -> next;
	}
	cout << endl;

	return;
}

bool Stack::isEmpty()
{
	return (top == NULL) ? true : false;
}

void postorderTraversal(tNode* root)
{
	Stack* s1 = new Stack();
	Stack* s2 = new Stack();
	
	tNode* current = root;
	
	s1 -> push(current);
	
	while(!s1 -> isEmpty())
	{
		current = s1 -> pop();
		
		s2 -> push(current);
		
		if(current -> left)
		{
			s1 -> push(current -> left);
		}
		
		if(current -> right)
		{
			s1 -> push(current -> right);
		}
	}
	
	s2 -> show();
}

tNode* newTNode(int data)
{
	tNode* t = new tNode();
	
	t -> data = data;
	t -> left = NULL;
	t -> right = NULL;
	
	return t;
}

int main()
{
	tNode* root 	=	newTNode(1);
	root -> left 	=	newTNode(2);
	root -> right 	=	newTNode(3);
	
	root -> left -> left	=	newTNode(4);
	root -> left -> right	= 	newTNode(5);
	
	postorderTraversal(root);

	return 0;
}
