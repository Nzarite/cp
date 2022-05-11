#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void printK(int a[], int n, int k){
    // priority_queue<int> pq(a,a+n); //timecomplexity O(nlogn)
    // while(k--){
    //     cout << pq.top()<<" ";
    //     pq.pop();
    // }
    priority_queue<int, vector<int>, greater<int>> pq(a,a+k); // timetaken O(klogk)
    for (int i = k; i < n;i++){ // timetaken O((n-k)logk)
        if(a[i]>pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()){ // timetaken O(klogk)
        cout << pq.top()<<" ";
        pq.pop();
    }
}
int main(){
    int a[] = {8, 6, 4, 10, 9};
    int k = 3;
    printK(a, 5, k); // timecomplexity : O(nlogk)
}