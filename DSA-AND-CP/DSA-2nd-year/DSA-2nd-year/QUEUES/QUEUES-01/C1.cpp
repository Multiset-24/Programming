#include <iostream>
#include <vector>
using namespace std;
//array and linkedlist implementation of queues

//most basic implementation of queues using array
class queue_v1{
    int f;
    int b;
    int s;
    vector<int>v;
    public:
    queue_v1(int val){
          f=0;
          b=0;
          s=0;
          vector<int>v(val);
    }
    void push(int val){
        v.push_back(val);
        b++;
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"stack underflow!!";
            return ;
        } 
        f++;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"stack underflow!!";
            return -1;
        }
        return v[f];
    }
    int back(){
        if(s==0){
            cout<<"stack underflow!!";
            return -1;
        }
        return v[b-1];
    }
    int size(){
        return s;
    }
    bool isempty(){
        if(s==0) return true;
        return false;
    }
};


//linked list implementation of queues
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue_v2 {
private:
    Node* front;
    Node* rear;

public:
    Queue_v2() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to add an element to the rear of the queue
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Queue becomes empty after dequeueing
        }
        delete temp;
    }

    // Function to get the front element of the queue
    int peek() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "Queue is empty. No element to peek." << endl;
            return -1; // Return an invalid value indicating an empty queue
        }
    }

    // Destructor to free memory allocated for nodes
    ~Queue_v2() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = rear = nullptr;
    }
};
int main() {
    queue_v1 q1(5);
    q1.pop();
    q1.push(5);
    cout<<endl<<q1.front();
    return 0;
}