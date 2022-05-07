#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};
void vSum(Node* root, int xD, map<int,int> &mp){
    if(root==NULL)
        return;
    vSum(root->left, xD - 1, mp);
    mp[xD] += root->key;
    vSum(root->right, xD + 1, mp);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(55);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(53);
    root->right->right = new Node(60);

    map<int,int> mp;
    vSum(root, 0, mp);
    for(auto sum: mp){
        cout << sum.second<< " ";
    }
    return 0;
}