#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct MinHeapNode{
    int val, pos, i;
    MinHeapNode(int v, int p, int idx){
        val = v;
        pos = p;
        i = idx;
    }
};
struct MyCmp{
    bool operator()(MinHeapNode &m1, MinHeapNode &m2){
        return m1.val > m2.val;
    }
};
vector<int> merge_k(vector<vector<int>> &v) // timecomplexity O(nklogk)
{
    vector<int> output;
    priority_queue<MinHeapNode, vector<MinHeapNode>, MyCmp> pq;
    for (int i = 0; i < v.size();i++){
        MinHeapNode m(v[i][0], i, 0);
        pq.push(m);
    }
    while(!pq.empty()){
        MinHeapNode curr = pq.top();
        pq.pop();
        output.push_back(curr.val);
        int ap = curr.pos;
        int vi = curr.i;
        if(vi+1<v[ap].size()){
            MinHeapNode m(v[ap][vi + 1], ap, vi + 1);
            pq.push(m);
        }
    }
    return output;
}
int main()
{
    vector<vector<int>> v{{10, 20, 30}, {5, 15}, {1, 9, 11, 18}};
    vector<int> output(merge_k(v));
    for(auto i : output){
        cout << i << " ";
    }
    return 0;
}