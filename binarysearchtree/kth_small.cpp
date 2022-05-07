#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{ // Augmented tree data structure
    int key, lcount;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
        lcount = 0;
    }
};
Node* insert(Node* root, int x){
    if(root==NULL)
        return new Node(x);
    if(x<root->key){
        root->left = insert(root->left, x);
        root->lcount++;
    }
    else if(x>root->key){
        root->right = insert(root->right, x);
    }
    return root;
}
Node* print_kth(Node* root, int k){ // efficient solution time complexity O(h) auxiliary space O(h)
    if(root==NULL)
        return NULL;
    int count = root->lcount + 1;
    if(count==k)
        return root;

    else if(k<count)
        return print_kth(root->left, k);

    else
        return print_kth(root->right, k - count);
}
int main(){
    Node* root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (int x : keys)
        root = insert(root, x);
    cout<<root->lcount;
    // int k;
    // cin >> k;
    // cout<<print_kth(root, k)->key;
}