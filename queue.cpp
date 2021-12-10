#include <iostream>
using namespace std;

template<typename T> class Queue{
    int front = -1, rear = 0, qSize;
    T* qArray;

public:
    Queue(){
        qArray = new T[10];
    }
    Queue(int size){
        qSize = size;
        qArray = new T[qSize];
    }

    bool isFull(){
        return (rear == qSize) ? true : false;
    }
    bool isEmpty(){
        return (front == qSize) ? true : false;
    }
    void enqueue(T data){
        if(isFull()){
            cout << "Queue is full!\n";
            return;
        }
        qArray[rear++] = data;
    }
    T& dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!\n";
        }
        return qArray[++front];
    }
};
int main(){

    Queue<string> q = Queue<string>(5);
    q.enqueue("Sakib");
    q.enqueue("Rakib");
    cout << q.dequeue() << " " << q.dequeue() << "\n";
    return 0;
}