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
bool check(Node* root, int min, int max){ // efficient solution timecomplexity O(n)
    if(root==NULL) // provide a range for the key value 
        return true;
    return (root->key>min && root->key<max && check(root->left, min, root->key) && check(root->right, root->key, max));
}
int prevv = INT_MIN;
bool check2(Node *root){ // efficient solution timecomplexity O(n) space complexity O(h)
    if(root==NULL) // check if inorder traversal is increasing without using auxiliary array
        return true;
    if(check2(root->left)==false)
        return false;
    if(root->key <= prevv)
        return false;
    prevv = root->key;
    return check2(root->right);
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

    int min = INT_MIN, max = INT_MAX;
    cout<<check(root, min, max);
    return 0;
}