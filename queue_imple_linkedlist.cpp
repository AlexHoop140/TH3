#include<iostream>
using namespace std;

struct node
{
	int data; 
	struct node *pNext; 
};
typedef node NODE;

struct queue
{
	NODE *pHead; 
	NODE *pTail;  
};
typedef queue QUEUE;

typedef int elementType; 

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

int pop(QUEUE &q)
{
  int x = -9999;
	if (isEmpty(q) == true)
	{
    cout << "[WARNING] Empty queue." << endl;
		return x;
	}
	else
	{
		NODE *p = q.pHead;
		x = p->data; 	
		q.pHead = q.pHead->pNext;	
		delete p;  

	}

  return x;
}


int top(QUEUE &q) 
{
  int x = -9999;
	if (isEmpty(q) == true)
	{
    cout << "[WARNING] Empty queue." << endl;
		return x;
	}
	x = q.pHead->data; 
	return x;
}


void deQueue(QUEUE q)
{
	while (isEmpty(q) == false)
	{
		int x;
		cout << pop(q) << " ";
	}
}

void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao queue - Push";
		cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = getNode(x);
			push(q, p);
		}
		else if (luachon == 2)
		{
			deQueue(q);
		}
		else if (luachon == 3)
		{
			cout << endl <<"Phan tu dau queue la: " << top(q);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	initQueue(q);

	NhapQueue(q);

	return 0;
}
