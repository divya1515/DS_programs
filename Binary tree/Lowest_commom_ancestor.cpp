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

Node* Lowest_common_ancestor(Node *&root,int x,int y)
{
     if(root==NULL)
     {
        return NULL;
     }
     if(root->data==x || root->data==y)
     {
        return root;
     }
     Node *l=Lowest_common_ancestor(root->left,x,y);
     Node *r=Lowest_common_ancestor(root->right,x,y);
     if(l==NULL)
     return r;
     if(r==NULL)
     return l;
     else
     return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->left = new Node(9);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    int x,y;
    cin>>x>>y;
    Node *s = Lowest_common_ancestor(root,x,y);
    cout<<s->data;
}
