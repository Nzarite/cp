#include <deque>
#include <iostream>
using namespace std;
struct My_DS
{
    deque<int> dq;
    void insertMin(int x)
    {
        dq.push_front(x);
    }
    void insertMax(int x)
    {
        dq.push_back(x);
    }
    int getMin()
    {
        return dq.front();
    }
    int getMax()
    {
        return dq.back();
    }
    void extractMin()
    {
        dq.pop_front();
    }
    void extractMax()
    {
        dq.pop_back();
    }
    void print()
    {
        for (auto it : dq)
            cout << it << " ";
    }
};
int main()
{
    My_DS ds;
    ds.insertMin(5);
    ds.insertMin(3);
    ds.insertMax(10);
    ds.insertMax(15);
    ds.insertMin(2);
    cout << ds.getMin() << endl;
    ds.extractMin();
    cout << ds.getMax() << endl;
    ds.insertMin(1);
    ds.print();
    return 0;
}