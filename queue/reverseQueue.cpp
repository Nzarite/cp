#include <queue>
#include <stack>
#include <iostream>
using namespace std;
void q_reverse(queue<int> &q) // iterative method
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void q_Rreverse(queue<int> &q) // recursive method
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    q_Rreverse(q);
    q.push(x);
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q_reverse(q);  // iterative
    q_Rreverse(q); // recursive
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}