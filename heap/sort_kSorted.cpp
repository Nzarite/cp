#include<iostream>
#include<queue>
using namespace std;

void sortk(int *a, int n, int k){ // timecomplexity : O(n+klogk)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k;i++) // time taken : klogk
        pq.push(a[i]);
    int index = 0;
    for (int i = k + 1; i < n; i++) // time taken :  O(n-klogk)
    {
        a[index++] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty()){ // time taken : O(klogk)
        a[index++] = pq.top();
        pq.pop();
    }
}
int main(){
    int a[]={9,8,7,19,18};
    sortk(a, 5, 2);
    for (int i = 0; i < 5;i++)
        cout << a[i]<<" ";
}