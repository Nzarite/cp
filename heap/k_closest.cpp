#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printk(int a[], int n, int k, int x){ // timecomplexity O(nlogk)
    priority_queue<pair<int, int>> pq; // first -> diff && second -> index
    for (int i = 0; i < k;i++) // time taken: O(klogk)
        pq.push(make_pair(abs(a[i] - x), i));
    for (int i = k; i < n; i++)// time taken: O((n-k)logk)
    {
        int diff = abs(a[i] - x);
        if (pq.top().first>diff){
            pq.pop();
            pq.push(make_pair(diff, i));
        }
    }
    for (int i = 0; i < k; i++) // time taken: O(klogk)
    {
        cout << a[pq.top().second] << " ";
        pq.pop();
    }
}
int main(){
    int a[] = {30, 40, 32, 33, 36, 37};
    int k = 3;
    int x = 38;
    printk(a, 6, k, x);
}