#include <bits/stdc++.h>
using namespace std;
//concept of Deque 

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Function to check if the deque is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to add an element to the front of the deque
    void push_front(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Function to add an element to the rear of the deque
    void push_back(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the deque
    void pop_front() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot pop from front." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // Deque becomes empty after popping from front
        }
        delete temp;
    }

    // Function to remove an element from the rear of the deque
    void pop_back() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot pop from back." << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // Deque becomes empty after popping from back
        }
        delete temp;
    }

    // Function to get the front element of the deque
    int front_element() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "Deque is empty. No front element." << endl;
            return -1; // Return an invalid value indicating an empty deque
        }
    }

    // Function to get the rear element of the deque
    int rear_element() {
        if (!isEmpty()) {
            return rear->data;
        } else {
            cout << "Deque is empty. No rear element." << endl;
            return -1; // Return an invalid value indicating an empty deque
        }
    }

    // Destructor to free memory allocated for nodes
    ~Deque() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = rear = nullptr;
    }
};

//concept of circular queue

class CircularQueue {
private:
    int front, rear;
    int size;
    int* arr;

public:
    CircularQueue(int capacity) : size(capacity), front(-1), rear(-1) {
        arr = new int[size];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }

    // Function to add an element to the rear of the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = item;
    }

    // Function to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek." << endl;
            return -1; // Return an invalid value indicating an empty queue
        }
        return arr[front];
    }

    // Destructor to free memory allocated for the array
    ~CircularQueue() {
        delete[] arr;
    }
};
int main() {
 
    return 0;
}