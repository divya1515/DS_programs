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
int CountN1(Node *&root)
{
    if (root == NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    return 0;
    if(root->left!=NULL && root->right!=NULL)
      return CountN1(root->left)+CountN1(root->right);
    return 1+CountN1(root->left)+CountN1(root->right);

}
void Strictly_binary_tree(Node* &root)
{
   int x=CountN1(root);
   if(x==0)
   cout<<"Strictly binary tree\n";
   else
   cout<<"Not a strictly binary tree\n";
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // root->right->right = new Node(7); 
    Strictly_binary_tree(root);
}
