#include <iostream>
using namespace std;
// implementation of stack using array/linked list
template <class T>
class stack
{
private:
    int idx = -1;
    T v[INT16_MAX];

public:
    stack()
    {
    }
    void push(T value)
    {
        if (idx + 1 >= INT16_MAX)
        {
            cout << "stack overflow" << endl;
            return;
        }
        idx++;
        v[idx] = value;
    }
    T top()
    {
        if (idx == -1)
        {
            cout << "stack is empty" << endl;
            return T();
        }
        return v[idx];
    }
    void pop()
    {
        if (idx == -1)
        {
            cout << "stack is empty ! cannot pop" << endl;
            return;
        }
        idx--;
    }
    int size()
    {
        if (idx == -1)
            return 0;
        return idx + 1;
    }
};

template <class T>
class lists
{
private:
    T val;
    lists *next;

public:
    lists(T val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
template <class T>
class Stack
{
    int sz = 0;
    lists<T>* head = nullptr;

public:
    int size()
    {
        return sz;
    }
    T top()
    {
        if (sz == 0)
        {
            cout << " stack underflow" << endl;
            return -1;
        }
        else
        {
            return head->val;
        }
    }
    void push(T val)
    {
        lists<T>* newnode = new lists<T>(val);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        sz++;
    }
    void pop()
    {
        if (sz == 0)
        {
            cout << " stack underflow" << endl;
        }
        else
        {
            lists<T>* temp = head;
            head = head->next;
            delete temp;
            sz--;
        }
    }
};
