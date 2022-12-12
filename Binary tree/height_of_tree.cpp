#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int height(Node *&root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->right->left = new Node(4);
    root->right->left->right = new Node(7);
    root->right->right = new Node(6);
    cout << height(root) << "\n";
}
