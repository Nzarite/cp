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
void topview(Node *root, int xD, map<int, int> &mp) // printing the top view of a binary tree : timecomplexity O(nlogn)
{                                                   // one can implement levelordertraversal also
    if (root == NULL)
        return;
    if (mp.find(xD) == mp.end()) // only push item in map if it doesn't exists prior
        mp[xD] = root->key;
    topview(root->left, xD - 1, mp);
    topview(root->right, xD + 1, mp);
}
int main()
{

    Node *root = new Node(50);
    root->left = new Node(60);
    root->right = new Node(55);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(53);
    root->right->right = new Node(30);

    map<int, int> mp;
    topview(root, 0, mp);

    for (auto it : mp)
        cout << it.second << " ";
    return 0;
}