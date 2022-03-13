#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << " " << q.back() << endl;
    q.pop();
    q.push(40);
    cout << q.front() << " " << q.back() << endl;
    cout << q.empty() << "\n";
    cout << q.size() << "\n";
}
