#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *Delete_binary_tree(Node *&root)
{
    if (root==NULL)
    {
        return NULL;
    }
    root->left=Delete_binary_tree(root->left);
    root->right=Delete_binary_tree(root->right);
     if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    return root;
}
void InorderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    if (root != NULL)
    {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}
void PreorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
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
    InorderTraversal(root);
    cout << "\n";

    Node *x = Delete_binary_tree(root);
    cout<<x;
}
