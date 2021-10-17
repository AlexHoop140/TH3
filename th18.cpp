#include <iostream>
#include "stack_imple_array.cpp"
using namespace std;

/*
Nhập danh sách stack chứa các số nguyên, sau đó xuất ra màn hình các giá trị số nguyên đó

*/
/*
// khai báo cấu trúc của 1 cái node trong stack
struct node
{
	int data; // stack đang chứa các số nguyên
	struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của stack
struct stack
{
	NODE *pTop; // dùng con trỏ đầu để quản lí stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá trị của biến x vào trong data của cái node
	p->pNext = NULL;
	return p;
}

// =============== KIỂM TRA STACK CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(STACK s)
{
	// nếu danh sách rỗng
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO ĐẦU STACK- LIFO ===============
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		s.pTop = p; // node p chính là node đầu stack
	}
	else // danh sách đã có phần tử
	{
		p->pNext = s.pTop; // cho con trỏ của node p trỏ đến node đầu danh sách <=> tạo kiên kết
		s.pTop = p; // cập nhật lại node đầu
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU STACK VÀ HỦY NÓ ĐI - LIFO ===============
bool Pop(STACK &s, int &x) // x chính là giá trị cần lấy trong node
{
	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; // node p chính là node thế mạng để tí nữa chúng ta xóa nó đi
		x = p->data; // gán giá trị của node đầu stack vào biến x	
		s.pTop = s.pTop->pNext; // cập nhật node đầu stack là node tiếp theo	
		delete p; // xóa node đầu stack vừa lấy 
		
	}
	return true;// lấy phần tử đầu stack thành công
}

// hàm xuất danh sách stack
void XuatStack(STACK s)
{
	while (IsEmpty(s) == false)
	{
		int x;
		Pop(s, x);
		cout << x << " ";
	}

	if (IsEmpty(s) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}
*/

int main(){
    int n = 123;
    int x;
    STACK s;
    initStack(s);
    // while (n > 0){
    //     NODE *p = getNode(n % 2);
    //     push(s, p);
    //     n /= 2;
    // }

    while(n > 0){
      elementType x = n % 2; 
      push(s, x);
      n /= 2;
    }


	
    printStack(s);
	
}