#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k - 1 < (n + 1) / 2)
        cout << 2 * (k - 1) + 1;
    else
        cout << 2 * ((k - 1) - (n + 1) / 2 + 1);
    return 0;
}