#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Deque
{
    int *arr;
    int front, size, cap;
    Deque(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void insertFront(int x)
    {
        if (isFull())
            return;
        front = (front + cap - 1) % cap;
        arr[front] = x;
        size++;
    }
    void insertRear(int x)
    {
        if (isFull())
            return;
        arr[(front + size) % cap] = x;
        size++;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[(front + size - 1) % cap];
    }
    void deleteFront()
    {
        if (isFull())
            return;
        front = (front + 1) % cap;
        size--;
    }
};
int main()
{
    Deque dq(6);
    dq.insertFront(40);
    dq.insertFront(30);
    dq.insertFront(20);
    dq.insertFront(10);
    cout << dq.getRear() << endl;
    dq.insertRear(50);
    dq.insertRear(60);
    cout << dq.getRear() << endl;
    dq.deleteFront();
    cout << dq.getFront() << endl;
    dq.deleteFront();
    dq.deleteFront();
    dq.deleteFront();
    dq.deleteFront();
    cout << dq.getFront() << endl;
    return 0;
}