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
int countNodes1(Node* root){ // NAIVE SOLUTION time complexity O(N)
    if(!root)
        return 0;
    return 1 + countNodes1(root->left) + countNodes1(root->right);
}
int countNodes2(Node* root){ // EFFICIENT SOLUTION time complexity O(log(h)*log(h)) 
    if(!root)
        return 0;
    int lh = 0;
    Node *temp=root;
    while (temp)
    {
        lh++;
        temp = temp->left;
    }
    temp = root;
    int rh = 0;
    while(temp){
        rh++;
        temp = temp->right;
    }
    if(lh==rh)
        return (int)pow(2, lh) - 1;
    return 1 + countNodes2(root->left) + countNodes2(root->right);
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

    // cout << countNodes1(root);
    cout << countNodes2(root);
    return 0;
}