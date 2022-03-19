#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Deque
{
    int *arr;
    int size, cap;
    Deque(int c)
    {
        arr = new int[c];
        cap = c;
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
        for (int i = size - 1; i >= 0; i--)
            arr[i + 1] = arr[i];
        arr[0] = x;
        size++;
    }
    void insertRear(int x)
    {
        if (isFull())
            return;
        arr[size] = x;
        size++;
    }
    void deleteFront()
    {
        for (int i = 0; i < size; i++)
            arr[i] = arr[i + 1];
        size--;
    }
    void deleteRear()
    {
        size--;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[0];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[size - 1];
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
    dq.deleteFront();
    cout << dq.getFront() << endl;
    return 0;
}