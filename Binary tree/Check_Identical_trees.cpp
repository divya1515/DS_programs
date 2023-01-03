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
int Check_identical(Node *&root, Node *&root1)
{
    if (root == NULL && root1 == NULL)
        return 1;
    if (root != NULL && root1 != NULL)
    {
        if (root->data == root1->data && Check_identical(root->left, root1->left) && Check_identical(root->right, root1->right))
        {
            return 1;
        }
        return 0;
    }
    return 0;
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
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(5);
    root1->right->left = new Node(4);
    root1->right->left->right = new Node(7);
    root1->right->right = new Node(6);
    int ans = Check_identical(root, root1);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
}
