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
void InorderTraversal(string &s, Node *&root)
{
    if (root == NULL)
        return;
    if (root != NULL)
    {
        InorderTraversal(s, root->left);
        s = to_string((root->data)) + s;
        InorderTraversal(s, root->right);
    }
}
void Inorder(Node *&root)
{
    if (root == NULL)
        return;
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
void PreorderTraversal(string &s, Node *&root)
{
    if (root != NULL)
    {
        s = to_string((root->data)) + s;
        PreorderTraversal(s, root->left);
        PreorderTraversal(s, root->right);
    }
}
int Search_pos(string Inorder, char x)
{
    for (int i = 0; i < Inorder.length(); i++)
    {
        if (Inorder[i] == x)
        {
            return i;
        }
    }
    return -1;
}
Node *Build_tree(string Inorder, string Postorder, int &index, int inorder_start, int inorder_end)
{

    if (index < 0 || inorder_start > inorder_end)
    {
        return NULL;
    }
    char element = Postorder[index--];
    Node *root = new Node((element) - '0');
    int pos = Search_pos(Inorder, element);
    root->right = Build_tree(Inorder, Postorder, index, pos + 1, inorder_end);
    root->left = Build_tree(Inorder, Postorder, index, inorder_start, pos - 1);
    return root;
}
Node *Mirror_Image(Node *&root)
{
    string inorder = "", postorder = "";
    InorderTraversal(inorder, root);
    PreorderTraversal(postorder, root);
    int index = postorder.length() - 1;
    int inorder_start = 0, inorder_end = inorder.length() - 1;
    Node *x = Build_tree(inorder, postorder, index, inorder_start, inorder_end);
    return x;
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
    Inorder(root);
    cout << "\n";
    Node *s = Mirror_Image(root);
    Inorder(s);
}
