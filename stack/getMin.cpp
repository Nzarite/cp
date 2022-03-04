#include <bits/stdc++.h>
#include <iostream>
using namespace std;
stack<int> ms;
stack<int> as;
void push(int x)
{
    ms.push(x);
    if (as.top() >= ms.top())
        as.push(x);
}
void pop()
{
    if (ms.top() == as.top())
        as.pop();
    ms.pop();
}
void getMin()
{
    cout << as.top() << "\n";
}
int main()
{

    push(5);
    push(10);
    getMin();
    push(2);
    getMin();
    pop();
    push(15);
    push(1);
    getMin();
    return 0;
}