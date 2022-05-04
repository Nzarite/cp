#include <set>
#include<iostream>
using namespace std;
void ceiling(int a[], int n){
    cout << -1<<" ";
    set<int> s;
    s.insert(a[0]);
    for (int i = 1; i < n;i++){
        if(s.lower_bound(a[i])==s.end())
            cout << -1<<" ";
        else
            cout << *(s.lower_bound(a[i]))<<" ";
        s.insert(a[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ceiling(a, n);
    return 0;
}