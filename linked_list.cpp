#include <iostream>
using namespace std;

template<typename T> class LinkedList{
    class Node{
    public:
        T data;
        Node *next;
        Node(){ 
            next = NULL;
        }
        Node(const T& data){
            this->data = data;
            next = NULL;
        }
    };
    Node* head;
    int length = 0;

public:
    LinkedList(){
        head = NULL;
    }

    bool isEmpty(){
        return (head == NULL) ? true : false;
    }
    void addAtFront(T data){
        Node* newNode = new Node(data);
        length++;
        if(isEmpty()){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(T data){
        Node* newNode = new Node(data);
        length++;
        if(isEmpty()){
            head = newNode;
            return;
        }
        head->next = newNode;
    }
    int size(){
        return length;
    }
    void deleteItem(const T& data){
        if(search(data)){
            Node *previousNode, *nextNode, *currentNode = head;   
            while(currentNode->data != data){
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            // to delete head node
            if(currentNode == head){
                head = currentNode->next;
                return;
            }

            nextNode = currentNode->next;
            if(nextNode != NULL){
                previousNode->next = nextNode;
            }
            else{
                previousNode->next = NULL;
            }  
        }
        else{
            cout << data << " item is not present in the list\n";
        }
    }
    bool search(const T& searchedData){
        if(isEmpty()){
            return false;
        }
        Node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->data == searchedData){
                return true;
            }
            tempNode = tempNode->next;
        }
        return false;
    }
    void printList(){
        Node* tempNode = head;
        if(isEmpty()){
            cout << "List is empty!\n";
            return;
        }
        while(tempNode != NULL){
            cout << tempNode->data << "-->";
            tempNode = tempNode->next;
        }
        cout << "\n";
    }
};




int main(){
    LinkedList<string> l;
    l.addAtFront("Sakib");
    l.addAtFront("Rakib");
    l.addAtFront("Didar");
    l.printList();
    cout << l.search("Didarul") << "\n";
    l.deleteItem("Didar");
    l.printList();

    return 0;
}