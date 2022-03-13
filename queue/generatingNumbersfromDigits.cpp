#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int count = 0; count < n; count++)
    {
        string curr = q.front();
        cout << curr << " ";
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
    return 0;
}