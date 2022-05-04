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
bool search(Node* root, int x){ // time complexity O(h) auxiliary space O(h)
    if(!root)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        return search(root->left,x);
    else
        return search(root->right,x);
}
Node* insert(Node* root, int x){
    if(!root)
        return new Node(x);
    else if(root->key<x)
        root->right=insert(root->right, x);
    else if(root->key>x)
        root->left=insert(root->left, x);
    return root;
}
void lvl1(Node* root){
    if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *curr = q.front();
        q.pop();
        if(curr==NULL){
            cout << "\n";
            q.push(NULL);
        }
        else{
            cout << curr->key << " ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}
Node* getSuccessor(Node* curr){
    curr = curr->right;
    while(curr && curr->left)
        curr = curr->left;
    return curr;
}
Node* dalit(Node* root, int x){
    if(!root)
        return root;
    if(root->key>x)
        root->left = dalit(root->left, x);
    else if(root->key<x)
        root->right = dalit(root->right, x);
    else{
        if(root->left==NULL){ // left subtree doesn't exist
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){ // right subtree doesn't exists
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{ // both the subtree exists
            Node *succ = getSuccessor(root);
            root->key = succ->key; // coopy the value of the succ to root
            root->right = dalit(root->right,succ->key); //  deleting the succ node
        }
        return root;
    }
    return NULL;
}
int floor(Node* root, int x){ // timecomplexity O(h)
    int res = -1;
    while (root)
    {
        if(root->key==x)
            return root->key;
        else if(root->key>x){
            root = root->left;
        }
        else{
            res = root->key;
            root = root->right;
        }
    }
    return res;
}
int ceil(Node* root, int x){ // timecomplexity O(h)
    int res = -1;
    while (root)
    {
        if(root->key==x)
            return root->key;
        else if(root->key>x){
            res = root->key;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return res;
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(55);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(53);
    root->right->right = new Node(60);
    
    cout<<search(root,53)<<endl;
    root=insert(root, 25);
    dalit(root, 50);
    cout << floor(root,35)<<endl;
    cout << ceil(root, 33)<<endl;
    // lvl1(root);

    return 0;
}