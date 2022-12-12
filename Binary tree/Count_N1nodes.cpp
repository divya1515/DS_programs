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
int CountN1(Node *&root)//parent with one children
{
    if (root == NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    return 0;
    if(root->left!=NULL && root->right!=NULL)
      return CountN1(root->left)+CountN1(root->right);
    return 1+CountN1(root->left)+CountN1(root->right);

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
    cout << CountN1(root) << "\n";
}
