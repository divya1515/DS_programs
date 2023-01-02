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
void PreorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}
void InorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}
void PostorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
}
int Max_path_Sum(int sum, Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
        return sum+root->data+max(Max_path_Sum(sum, root->left), Max_path_Sum(sum, root->right));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    int s = 0;
    s = Max_path_Sum(0, root);
    cout << s << "\n";
}
