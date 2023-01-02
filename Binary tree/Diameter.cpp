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
int height(Node *&root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    return 1+max(height(root->left),height(root->right));
}
int Diameter(Node *&root)
{
    if(root==NULL)
     return 0;
     else
     {
        int d1=1+height(root->left)+height(root->right);
        int d2=Diameter(root->left);
        int d3=Diameter(root->right);
        int M=max({d1,d2,d3});
        return M;
     }
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
    s = Diameter(root);
    cout << s << "\n";
}
