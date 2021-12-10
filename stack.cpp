#include <iostream>
using namespace std;

template <class T> class Stack{
private:
    T *stack;
    int sizeOfArray;
    int top;

public:
    Stack(){ 
        sizeOfArray = 10;
        stack = new T[sizeOfArray];
        top = -1;
    }
    Stack(int size){
        sizeOfArray = size;
        stack = new T[sizeOfArray];
        top = -1;
    }

    bool isFull(){
        return (top == sizeOfArray) ? true : false;
    }

    bool isEmpty(){
        return (top == -1) ? true : false;
    }

    void push(T data){
        if(isFull()){
            cout << "Stack is full!\n";
            return;
        }
        stack[++top] = data;
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
            return NULL;
        }
        return stack[top--];
    }

    T topElement(){
        return stack[top];
    }

    int size(){
        return sizeOfArray;
    }
    ~Stack(){
        delete[] stack;
    }
};

int main(){
    Stack<char> s(5);
    cout << "size = " << s.size() << "\n";
    return 0;
}