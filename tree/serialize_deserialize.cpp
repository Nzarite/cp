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
void ser(Node* root, vector<int> &v){
    if(root==NULL)
    {
        v.push_back(-1);
        return;
    }
    // preorder traversal
    v.push_back(root->key);
    ser(root->left,v);
    ser(root->right,v);
}
int indx=0;
Node *deser(vector<int> v)
{
    if(indx==v.size())
        return NULL;
    int val = v[indx];
    indx++;
    if(val==-1)
        return NULL;
    Node *root = new Node(val);
    root->left = deser(v);
    root->right = deser(v);
    return root;
}    
void preorder(Node *root) // time complexity O(n) // auxiliary space O(h)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(100);

    vector<int> v;
    ser(root,v);
    for(auto it: v)
        cout << it << " ";
    cout << endl;
    root = deser(v);
    preorder(root);
    return 0;
}