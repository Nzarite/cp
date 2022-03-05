#include <queue>
#include <iostream>
using namespace std;
struct Stack
{
    queue<int> q1, q2;
    int top() { return q1.front(); }
    int size() { return q1.size(); }
    int pop() { return q1.front(); }
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(15);
    s.push(20);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    return 0;
}