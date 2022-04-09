#include <iostream>
#include <limits.h>
#include <stack>
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
void iter_in(Node* root){
    stack<Node *> last_node;
    Node* curr = root;
    while(curr || !last_node.empty()){
        while(curr){
            last_node.push(curr);
            curr = curr->left;
        }
        curr = last_node.top();
        cout << curr->key << " ";
        last_node.pop();
        curr = curr ->right;
    }
    cout << endl;
}
void iter_pre(Node* root){
    stack<Node *>last_pro;
    last_pro.push(root);
    while (!last_pro.empty())
    {
        Node *curr = last_pro.top();
        cout << curr->key<<" ";
        last_pro.pop();
        if(curr->right)
            last_pro.push(curr->right);
        if(curr->left)
            last_pro.push(curr->left);
    }
    cout << endl;
}
void iter_pre2(Node* root){
    if(root==NULL)
        return;
    stack<Node *> last_node;
    Node *curr = root;
    while(curr || !last_node.empty())
    {
        while (curr)
        {
            cout << curr->key << " ";
            if(curr->right)
                last_node.push(curr->right);
            curr = curr->left;
        }
        if(!last_node.empty()){
            curr = last_node.top();
            last_node.pop();
        }
    }
    cout << endl;
}
void iter_post(Node* root){
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
    
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->key << " ";
    }
}
void iter_post2(Node* root){
    stack<Node *> s;
    if(!root)
        return;
    do
    {   
        while(root)
        {
            if(root->right)
                s.push(root->right);
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(root->right && s.top()==root->right){
            s.pop();
            s.push(root);
            root = root->right;
        }
        else{
            cout << root->key<<" ";
            root = NULL;
        }
    } while (!s.empty());
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->right->right = new Node(900);
    root->right->left = new Node(640);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(100);

    iter_in(root);
    iter_pre(root);
    // iter_pre2(root);
    // iter_post(root);
    iter_post2(root);
    return 0;
}