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
bool findPath(Node* root, vector<Node*> &p, int n){
    if(!root)
        return false;
    p.push_back(root);
    if(root->key==n)
        return true;
    if(findPath(root->left,p,n)||findPath(root->right,p,n))
        return true;
    p.pop_back();
    return false;
}
int lca1(Node* root, int n1, int n2){ // NAIVE SOLUTION time complexity: THETA(N) AUXILIARY SPACE: O(N)
    vector<Node *> path1, path2;     // REQUIRES THREE TRAVERSALS
    if((findPath(root,path1,n1)==false)||(findPath(root, path2, n2)==false))
        return -1;
    // for (int i = 0; i < path1.size();i++)
    //     cout << path1[i]->key<<" ";
    // cout << endl;
    // for (int i = 0; i < path2.size(); i++)
    //     cout << path2[i]->key<<" ";
    path1.push_back(NULL);
    path2.push_back(NULL);
    for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
    {
        if(path1[i+1]==NULL)
            return path1[i]->key;
        else if(path2[i+1]==NULL)
            return path2[i]->key;
        else if(path1[i + 1] != path2[i + 1])
            return path1[i]->key;
    }
    return -1;
}
int lca2(Node* root, int n1, int n2){ // EFFICIENT SOLUTION time complexity: THETA(N) AUXILIARY SPACE: O(H)
    if(!root)                         // REQUIRES ONE TRAVERSAL
        return 0;
    if(root->key==n1||root->key==n2)
        return root->key;

    int lcaL = lca2(root->left, n1, n2);
    int lcaR = lca2(root->right, n1, n2);

    if (lcaL && lcaR)
        return root->key;
    if(lcaL)
        return lcaL;
    else
        return lcaR;
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(100);

    int n1, n2;
    cin >> n1 >> n2;
    // cout << lca1(root, n1, n2);
    cout << lca2(root, n1, n2);
    return 0;
}