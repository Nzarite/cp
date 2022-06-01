#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[],  int s, bool visited[]){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFSDis(vector<int> adj[], int v){
    bool visited[v + 1];
    for (int i = 0; i < v;i++){
        if(visited[i]==false)
            BFS(adj, i, visited);
    }
}