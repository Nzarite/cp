#include <set>
#include<iostream>
using namespace std;

int main()
{
    // set<int> s; // arranges the elements in increasing order
    set<int, greater<int>> s; // arranges the elements in decreasing order
    s.insert(10);
    s.insert(5);
    s.insert(20);
    for (auto i:s)
        cout << i <<" ";
    if(s.find(20)==s.end())
        cout << "NOT FOUND\n";
    else
        cout << "FOUND\n";
    s.clear();
    cout<<s.size()<<"\n";
    s.erase(10);
    return 0;
}