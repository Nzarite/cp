#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int *medians(int a[], int n){ // timecomplexity : nlogn
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    s.push(a[0]);
    cout << a[0] << "\n";
    for (int i = 1; i < n;i++){
        int x = a[i];
        if(s.size()>g.size()){
            if(s.top()>x){
                g.push(x);
                s.pop();
                s.push(x);
            }
            else g.push(x);
            cout << (double)(s.top() + g.top()) / 2; 
        }
        else{
            if(x<s.top())
                s.push(x);
            else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
}
int main()
{
    int a[] = {25, 7, 10, 15, 20};
    medians(a,5);
    return 0;
}