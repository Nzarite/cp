#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int maxItems(int cost[], int n, int sum){
    priority_queue<int, vector<int>, greater<int>> pq(cost,cost+n);
    int ans = 0;
    while (sum-pq.top()>0)
    {
        sum -= pq.top();
        pq.pop();
        ans++;
    }
    return ans;
}
int main()
{
    int cost[] = {20, 10, 5, 30, 100};
    int sum = 40;
    cout<<maxItems(cost, 5, sum);
    return 0;
}