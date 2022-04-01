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
int preIndex = 0;
Node *btfrominpre(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    }
    root->left = btfrominpre(in, pre, is, inIndex - 1);
    root->right = btfrominpre(in, pre, inIndex + 1, ie);
    return root;
}
void inorder(Node *root) // time complexity O(n) // auxiliary space O(h)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
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
void postorder(Node *root) // time complexity O(n) // auxiliary space O(h)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int in[n], pre[n];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    Node *root = btfrominpre(in, pre, 0, n - 1);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}