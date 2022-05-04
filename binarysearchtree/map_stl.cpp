#include <map>
#include<iostream>
using namespace std;

int main()
{
    map<int, int> m;
    m.insert({10, 200});
    m[5] = 100;
    m.insert({20, 300});
    m[5] = 400;
    m.insert({10, 800});
    for (auto &it : m)
        cout << it.first << " " << it.second<<"\n";
    m.erase(m.find(10));
    return 0;
}