#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int min_time = INT_MAX, time, index;
    int count;
    for (int i = 0; i < n; i++)
    {
        cin >> time;
        if (time < min_time)
        {
            min_time = time;
            index = i;
            count = 1;
        }
        else if (time == min_time)
        {
            count++;
        }
    }
    if (count == 1)
        cout << index + 1;
    else
        cout << "Still Rozdil";
    return 0;
}