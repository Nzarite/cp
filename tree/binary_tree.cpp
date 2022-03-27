#include <iostream>
#include <limits.h>
#include <queue>
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
int height(Node *root) // to calculate the height of the tree
{
    if (root)
        return max(height(root->left), height(root->right)) + 1;
    return 0;
}
void nodesAtk(Node *root, int k) // time complexity O(n) // auxiliary space O(h)
{
    if (root == NULL)
    {
        cout << "* ";
        return;
    }
    if (k == 0)
    {
        cout << root->key << " ";
        return;
    }
    nodesAtk(root->left, k - 1);
    nodesAtk(root->right, k - 1);
}
void level_order_traversal(Node *root, int h)
{
    /* time complexity O(n*h)
    int i = 0;
    while (i < h)
    {
        nodesAtk(root, i);
        i++;
        cout << "\n";
    }
    */
    // timecomplexity O(n)
    queue<Node *> q;
    if (root == NULL)
        return;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
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
void level_order_traversal_lBl_2(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << "\n";
    }
}
int size_tree(Node *root) // time complexity O(n) auxiliary space O(h)
{
    if (!root)
        return 0;
    return 1 + size_tree(root->left) + size_tree(root->right);
}
int max_tree_element(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(max_tree_element(root->left), max_tree_element(root->right)));
}
void print_leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << "\n";
    }
}
bool is_childrenSumProperty(Node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    int sum = 0;
    if (root->left)
        sum += root->left->key;
    if (root->right)
        sum += root->right->key;
    return (sum == root->key && is_childrenSumProperty(root->left) && is_childrenSumProperty(root->right));
}
bool is_balancedTree(Node *root)
{
    /*  // NAIVE SOLUTION O(N^2)
    if (!root)
        return true;
    if (abs(height(root->left) - height(root->right)) > 1)
        return false;
    return (is_balancedTree(root->left) && is_balancedTree(root->right));
    */
    // EFFICIENT SOLUTION O(N)
    if (!root)
        return 0;
    int lh = is_balancedTree(root->left);
    if (lh == -1)
        return -1;
    int rh = is_balancedTree(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}
int max_width(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return res;
}
Node *prevv = NULL;
Node *bt_to_dll(Node *root)
{
    if (!root)
        return root;
    Node *head = bt_to_dll(root->left);
    if (prevv == NULL)
        head = root;
    else
    {
        root->left = prevv;
        prevv->right = root;
    }
    prevv = root;
    bt_to_dll(root->right);
    return head;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->right = new Node(50);

    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";

    cout << height(root) << "\n";

    int k;
    cin >> k;
    nodesAtk(root, k);
    cout << "\n";

    level_order_traversal(root, height(root));
    cout << "\n";
    level_order_traversal_lBl_1(root);
    cout << "\n";
    // level_order_traversal_lBl_2(root);
    cout << size_tree(root) << "\n";

    cout << max_tree_element(root);
    cout << "\n";

    print_leftView(root);

    cout << is_childrenSumProperty(root) << "\n";

    cout << is_balancedTree(root) << "\n";

    cout << max_width(root) << "\n";
}
