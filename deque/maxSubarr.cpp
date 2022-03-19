#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<int> dq; // inserting the index of arr elements in deque
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && a[i] >= dq.back())
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << a[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k) // removing the initial elements which are not part of the further windows
            dq.pop_front();
        while (!dq.empty() && a[i] > a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << a[dq.front()];
    return 0;
}