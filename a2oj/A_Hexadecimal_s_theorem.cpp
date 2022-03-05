#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int fib(int n)
{
    int n1 = 0;
    int n2 = 1;
    while (n2 + n1 != n)
    {
        int fib = n1 + n2;
        n1 = n2;
        n2 = fib;
    }
    cout << 0 << " " << n1 << " " << n2;
}
int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << 0 << " " << 0 << " " << 0;
    else
        fib(n);
    // cout << 0 << " " << 0 << " " << 0;   best answer :}
    return 0;
}