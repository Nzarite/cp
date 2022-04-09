#include <iostream>
#include <queue>
#include <limits.h>
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
void level_order_traversal_lBl_1(Node *root) // time complexity O(n) // auxiliary space theta(w)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
        }
        else
        {
            cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}
bool search(Node* root, int x){
    if(!root)
        return false;
    else if(root->key==x)
        return false;
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(55);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(57);
    root->right->right = new Node(60);
    
    // level_order_traversal_lBl_1(root);
    search(root,57);

    return 0;
}