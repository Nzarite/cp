#include <bits/stdc++.h>
#include <iostream>
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
Node *prevv;
Node *bttodll(Node *root)
{
    if (!root)
        return root;
    Node *head = bttodll(root->left);
    if (!prevv)
        head = root;
    else
    {
        root->left = prevv;
        prevv->right = root;
    }
    prevv = root;
    bttodll(root->right);
    return head;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->right = new Node(50);

    Node *val = bttodll(root);
    while (val)
    {
        cout << val->key << " ";
        val = val->right;
    }
    return 0;
}