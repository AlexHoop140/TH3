#include<iostream>
using namespace std;

typedef int elementType;

struct node
{
	elementType data;
	node *pNext; 
};
typedef node NODE;

struct stack
{
	NODE *pTop;
};
typedef stack STACK;

// hàm khởi tạo stack
void initStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *getNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool isEmpty(STACK s){
  if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}

void push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
    cout << "[WARNING] Stack is empty." << endl;
		return;
	}

	if (isEmpty(s) == true){
		s.pTop = p; 
	}
	else {
		p->pNext = s.pTop; 
		s.pTop = p; 
	}
}

void pop(STACK &s) {
  if (isEmpty(s) == true){
		cout << "[WARNING] Stack is empty." << endl;
		return;
	}
	else
	{
		NODE *p = s.pTop; 
		s.pTop = s.pTop->pNext; 
		delete p; 
	}
}

elementType top(STACK &s) 
{
  elementType x;
	if (isEmpty(s) == true)
	{
    cout << "[WARNING] Stack is empty." << endl;
		return x;
	}
	x = s.pTop->data; 
	return x;
}

void printStack(STACK s)
{
	while (isEmpty(s) == false)
	{
    elementType x = top(s);
		cout << x << " ";
    pop(s);
	}
}

void inputStack(STACK &s)
{
	int choice;
	while (true)
	{
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Insert one element to stack - Push";
		cout << "\n\t2. Print all elements in stack - Print";
		cout << "\n\t3. Show data of the top element in stack - Top";
		cout << "\n\t0. Quit";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nEnter your choice: ";
		cin >> choice;
		// cin.ignore();
		if (choice == 1){
			elementType x;
			cout << "\nType in one element to push: ";
			cin >> x;
			// getline(cin, x, '\n');
			NODE *p = getNode(x);
			push(s, p);
		}
		else if (choice == 2){
			printStack(s);
		}
		else if (choice == 3){
			cout << endl <<"Data of the top of stack: " << top(s);
		}
		else{
			break;
		}
	}
}
/*
int main()
{
	STACK s;
	KhoiTaoStack(s);

	NhapStack(s);

	return 0;
}*/