#include <bits/stdc++.h>
int flag = 1;
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
int sum(Node* &root,int &s)
{
   if (root != NULL)
    {
        s+=root->data;
        sum(root->left,s);
        sum(root->right,s);
    }
    return s;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7); 
    int s=0;
    cout<<sum(root,s)<<"\n";
}
