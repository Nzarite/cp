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
void vot(Node* root, int xD, map<int, vector<int>> &mp){ // preorder traversal timecomplexity : O(nlogxD)
    // queue<pair<Node *, int>> q; // one can also do levelordertraversal
    if(root==NULL)
        return;
    mp[xD].push_back(root->key);
    vot(root->left, xD - 1, mp);
    vot(root->right, xD + 1, mp);
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

    map<int, vector<int>> mp;
    vot(root,0,mp);
    for(auto it: mp){
        for(auto jt: it.second) // to print the vector
            cout << jt << " ";
        cout << endl;
    }
    return 0;
}