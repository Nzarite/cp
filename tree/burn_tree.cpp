#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int countPath = 0;
int burnTime(Node *root, int leaf, int &dist)
{
    if(!root)
        return 0;
    if(root->key==leaf){
        dist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist);
    int rh = burnTime(root->right, leaf, rdist);
    if(ldist!=-1){
        dist = ldist + 1;
        countPath = max(countPath, dist + rh);
    }
    else if(rdist!=-1){
        dist = rdist + 1;
        countPath = max(countPath, dist + lh);
    }
    return max(lh, rh) + 1;
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(100);

    int leaf;
    cin >> leaf;
    int dist = 0;
    cout<<burnTime(root, leaf, dist);
    return 0;
}