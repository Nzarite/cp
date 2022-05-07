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
Node *prevv, *first, *second;
void fix(Node* root){ // find the swapped values of bst
    if(root==NULL) // using inorder traversal increasing technique
        return;
    fix(root->left);
    if(prevv!=NULL && root->key<prevv->key){
        if(first==NULL)
            first = prevv;
        second = root;
    }
    prevv = root;
    fix(root->right);
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

    fix(root);
    cout << first->key << " " << second->key;
    return 0;
}