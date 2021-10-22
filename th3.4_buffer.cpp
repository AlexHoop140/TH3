#include <iostream>
#include <fstream>
// #include <sstream>
#define MaxLength 10;

using namespace std;

typedef string elementType;

typedef struct{
    elementType elements[10];
    int front, rear;
} Queue;

void init(Queue &q){
    q.front = -1;
    q.rear = -1; 
}

bool isEmpty(Queue q){
    return q.front == -1;
}

bool isFull(Queue q){
    return (q.rear - q.front + 1) == MaxLength;
}

void dequeue(Queue &q){
    if(!isEmpty(q)){
        q.front = q.front + 1;
        if(q.front > q.rear) init(q);
    }
    else 
        cout << "[ERROR] Empty Queue!" << endl;
}

void enqueue(elementType row, Queue &q){
    if(!isFull(q)){
        if(isEmpty(q)) 
            q.front = 0;
        if(q.rear == (10 - 1)){
            for(int i = q.front; i <= q.rear; i++)
                q.elements[i-q.front] = q.elements[i];
        
            q.rear = 10 - q.front - 1;
            q.front = 0;
        }
        q.rear = q.rear + 1;
        q.elements[q.rear] = row; 
    }
    else
        cout << "[ERROR] Full Queue!" << endl;
}
/*
void buffer(ifstream &fileIn, Queue &q){
    fileIn.open("input.txt", ios_base::in);

    if(!fileIn){
        cout << "Khong tim thay tep tin" << endl;
        exit(0);
    };
    string str;
    while(getline(fileIn, str, '\n')){
        if(!isFull(q)){
            enqueue(str, q);
        }
        else{
            cout << "In tu hang......" << endl;
            while(!isEmpty(q)){
                // elementType str2 = q.elements[q.front];
                cout << q.elements[q.front] << endl;
                dequeue(q);
            }
        }

        enqueue(str, q);
    }

    // if(!isEmpty(q)){
        cout << "In cac noi dung con lai trong hang doi...." << endl;
        while(!isEmpty(q)){
            elementType str3 = q.elements[q.front];
            cout << str3 << endl;
            dequeue(q);
        }
    // }
    fileIn.close();
}
*/


int main(){
    ifstream fileIn;
    Queue q;
    init(q);
    // buffer(fileIn, q);

    fileIn.open("input.txt", ios_base::in);

    if(!fileIn){
        cout << "[ERROR] CANNOT FIND THE FILE" << endl;
        exit(0);
    };
    string str;
    while(getline(fileIn, str)){
        if(!isFull(q)){
            enqueue(str, q);
        }
        else{
            cout << endl << "PRINTING ......" << endl;
            while(!isEmpty(q)){
                cout << q.elements[q.front] << endl;
                dequeue(q);
            }
            // Neu queue full thi in ra het queue, sau do enqueue line moi vao 
            enqueue(str, q);
        }

        // enqueue(str, q);
    }

    if(!isEmpty(q)){
    cout << endl << "PRINTING REMAINING ELEMENTS IN QUEUE...." << endl;
        while(!isEmpty(q)){
            elementType str3 = q.elements[q.front];
            cout << str3 << endl;
            dequeue(q);
        }
    }
    fileIn.close();

}