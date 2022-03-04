#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Queue
{
    int *arr;
    int front, rear, size, cap;
    Queue(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }
    void enque(int x)
    {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void deque()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }
    bool isFull() { return (cap == size); }

    bool isEmpty() { return (size == 0); }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Queue q(6);
    q.enque(5);
    q.deque();
    q.enque(15);
    q.enque(25);
    q.enque(35);
    q.deque();
    q.enque(45);
    cout << q.isEmpty() << "\n";
    cout << q.isFull() << "\n";
    q.print();
    return 0;
}
