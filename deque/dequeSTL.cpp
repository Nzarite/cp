#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<int> dq = {10, 20, 30};
    dq.push_front(0);
    dq.push_back(40);
    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << endl;
    auto it = dq.begin();
    // cout << *it << endl;
    dq.insert(it + 1, 5);
    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << endl
         << dq.size() << endl;
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}