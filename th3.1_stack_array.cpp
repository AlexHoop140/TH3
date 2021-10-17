#include <iostream>
#define maxLength 100

using namespace std;

typedef int elementType;

typedef struct{
  elementType Elements[maxLength];
  int topIndex;
} Stack;

typedef Stack STACK;

void initStack(STACK &s){
  s.topIndex = maxLength;
}

bool isEmpty(STACK s){
  return s.topIndex == maxLength;
}

bool isFullStack(STACK s){
  return s.topIndex == 0;
}

elementType top(STACK s){
  elementType x;
  if(!isEmpty(s)){
    x = s.Elements[s.topIndex];
    return x;
  }
  else{
    cout << "[WARNING] Stack is empty." << endl;
    return x;
  }
}

void pop(STACK &s){
  if(!isEmpty(s)){
    s.topIndex++;
  } else{
    cout << "[WARNING] Stack is empty." << endl;
  }
}

void push(STACK &s, elementType x){
  if(isFullStack(s)){
    cout << "[WARNING] Stack is full." << endl;
  }else{
    s.topIndex--;
    s.Elements[s.topIndex] = x;
  }
}

void printStack(STACK s){
  while(!isEmpty(s)){
    elementType x = top(s);
    cout << x << " ";
    pop(s);
  }
}
