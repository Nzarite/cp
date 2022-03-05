#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = a[0];
    int diff = abs(a[0] - a[1]);
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i + 1]) < diff)
        {
            idx = i;
            diff = abs(a[i] - a[i + 1]);
        }
    }
    cout << idx % n + 1 << " " << (idx + 1) % n + 1;
    return 0;
}