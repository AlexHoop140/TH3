#include <iostream>
#include <sstream>
#include <string>
using namespace std;


typedef string elementType; 

struct node
{
	elementType data; 
	struct node *pNext; 
};
typedef node NODE;

struct queue
{
	NODE *pHead; 
	NODE *pTail;  
};
typedef queue QUEUE;


// ham khoi tao queue
void initQueue(QUEUE &q)
{
	q.pHead = new NODE();
	q.pHead = NULL;
	q.pTail = NULL;
}

// ham tao node
NODE *getNode(elementType x)
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

bool isEmpty(QUEUE q)
{
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}

//Ham push 1 phan tu moi vao queue
void push(QUEUE &q, NODE *p)
{
	if (p == NULL){
		return;
	}

	if (isEmpty(q) == true){
		q.pHead = q.pTail = p; 
	}
	else{
		q.pTail->pNext = p; 
		q.pTail = p; 
	}
}

//Ham bo 1 phan tu ra khoi queue
void pop(QUEUE &q)
{
	if (isEmpty(q) == true)
	{
    		cout << "[WARNING] Empty queue." << endl;
    		return;
	}
	else
	{
		NODE *p = q.pHead;
		q.pHead = q.pHead->pNext;	
		delete p;  

	}
}

//Ham thong tin cua phan tu dau tien
elementType top(QUEUE &q) {
	elementType x;
	if (isEmpty(q) == true)
	{
    		cout << "[WARNING] Empty queue." << endl;
		return x;
	}
	x = q.pHead->data; 
	return x;
}

void printQueue(QUEUE q)
{
	while (isEmpty(q) == false)
	{
		elementType x = top(q);
		cout << x << " ";
		pop(q);
	}
}

void inputQueue(QUEUE &q)
{
	int choice;
	while (true)
	{
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Insert one element to queue - Push";
		cout << "\n\t2. Print all elements in queue - Pop";
		cout << "\n\t3. Show data of the top element in queue - Top";
		cout << "\n\t0. Quit";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nEnter your choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1){
			elementType x;
			cout << "\nType in one element to push: ";
			// cin >> x;
			getline(cin, x, '\n');
			NODE *p = getNode(x);
			push(q, p);
		}
		else if (choice == 2){
			printQueue(q);
		}
		else if (choice == 3){
			cout << endl <<"Data of the top of queue: " << top(q);
		}
		else{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	initQueue(q);

	inputQueue(q);

	return 0;
}
