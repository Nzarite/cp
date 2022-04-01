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
        left = NULL;
        right = NULL;
    }
};
void traverseSpiral_1(Node *root) // NAIVE SOLUTION O(N) EXTRA WORK DONE FOR PRINTING IN SPIRAL ORDER
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (reverse)
                s.push(curr->key);
            else
                cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (reverse)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}
void traverseSpiral_2(Node *root)
{
    stack<struct Node *> s1;
    stack<struct Node *> s2;
    if (root == NULL)
        return;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            cout << temp->key << " ";
            s1.pop();
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }
        cout << endl;
        while (!s2.empty())
        {
            Node *temp = s2.top();
            cout << temp->key << " ";
            s2.pop();
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
        cout << endl;
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // traverseSpiral_1(root);
    traverseSpiral_2(root);
    return 0;
}