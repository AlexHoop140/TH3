#include <iostream>
#include "th3.1_stack_array.cpp"
using namespace std;

int main(){
    int n = 1234;
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
