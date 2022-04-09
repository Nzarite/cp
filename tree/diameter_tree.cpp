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
int height(Node* root){
    if(!root)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}
int diaTree(Node* root){ // NAIVE SOLUTION time complexity O(N^2)
    if(!root)
        return 0;
    int dia = 1 + height(root->left) + height(root->right);
    return max(dia,max(diaTree(root->left), diaTree(root->right)));
}
unordered_map<Node *, int> um;
int height1(Node* root){
    if(!root)
        return 0;
    return 1 + um[root];
}
void diaTree1(Node* root){// BETTER SOLUTION time complexity O(N) with space O(N)
    if(!root)
        return;
    if(root->left)diaTree1(root->left);
    if(root->right)diaTree1(root->right);
    um[root] = height1(root);
}
int diaTree2(Node* root,int dia){ // EFFICIENT SOLUTION time complexity O(N) with space O(h)
    if(!root)
        return 0;
        dia = max(dia, 1+height(root->left)+height(root->right));
        return dia;
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

    // cout << diaTree(root);
    // diaTree1(root);
    // for(auto it: um){
    //     cout<< it.second<<" "<<it.first->key<<endl;
    // }
    cout<<diaTree2(root,0);
    return 0;
}