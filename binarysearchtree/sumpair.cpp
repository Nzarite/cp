// to check if a pair is present in bst whose sum is equal to given sum
#include <unordered_set>
#include <vector>
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
void getArr(Node* root, vector<int> &v){
    if(root)
    {
        getArr(root->left, v);
        v.push_back(root->key);
        getArr(root->right, v);
    }
}
bool isPresent(Node* root, int sum){ // inorder traversal method time complexity = auxiliary space = theta(n) 
    vector<int> v;
    getArr(root, v); // get inorder traversal in the form of array

    // apply two pointer approach to find the pair sum in increasing array
    int left=0, right=v.size()-1;
    while(left<right){
        if(v[left]+v[right]==sum)
            return true;
        else if(v[left]+v[right]>sum)
            right--;
        else
            left++;
    }
    return false;
}

unordered_set<int> s;
bool isPresent2(Node* root, int sum){ // using hashing timecomplexity = auxiliary space = O(n)
    if(root==NULL)
        return false;
    if(isPresent2(root->left, sum)== true)
        return true;
    if(s.find(sum-root->key)!=s.end())
        return true;
    else
        s.insert(root->key);
    return isPresent2(root->right, sum);
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

    int sum;
    cin >> sum;

    cout<<isPresent2(root, sum);

    return 0;
}