#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *father;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->father = NULL;
    }
};
void InorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}
void InsertBinary_Search_tree(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }

    Node *p = NULL;
    Node *q = root;
    while (q != NULL)
    {
        p = q;
        if (x < q->data)
        {
            q = q->left;
        }
        else
        {
            q = q->right;
        }
    }
    if (x < p->data)
    {
        p->left = new Node(x);
        p->left->father = p;
    }
    else
    {
        p->right = new Node(x);
        p->right->father = p;
    }
}
Node *Minimum(Node *&root)
{
    Node *p = root;
    while (p->left != NULL)
    {
        p = p->left;
    }
    return p;
}
Node *Successor(Node *p)
{
    Node *q;
    if (p->right != NULL)
    {
        q = Minimum(p->right);
    }
    else
    {
        q = p->father;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->father;
        }
    }
    return q;
}
int Isleft(Node *p)
{
    if (p->father->left == p)
        return 1;
    else
        return 0;
}
int Isright(Node *p)
{
    if (p->father->right == p)
        return 1;
    else
        return 0;
}
Node *IsSibling(Node *p)
{
    if (Isleft(p))
        return p->father->right;
    else
        return p->father->left;
}
int deletion(Node *&root, Node *p)
{
    if (p->left == NULL && p->right == NULL)
    {
        Node *q = p->father;
        if (q == NULL)
        {
            root = NULL;
        }
        else
        {
            if (Isleft(p))
            {
                q->left = NULL;
            }
            else
            {
                q->right = NULL;
            }
        }
        int x = p->data;
        delete p;
        return x;
    }
    else 
    if (p->left == NULL || p->right == NULL)
    {
        Node *l = p->left;
        Node *r = p->right;
        Node *q = p->father;
        Node *child;
        if (l == NULL)
        {
            child = r;
        }
        else
        {
            child = l;
        }
        if (q != NULL)
        {
            if (Isleft(p))
                q->left = child;
            else
                q->right = child;
        }
        else
        {
            if (p->right != NULL)
                root = p->right;
            else
                root = p->left;
        }
        child->father = q;
        int x = p->data;
        delete p;
        return x;
    }
    Node *q = Successor(p);
    int x = deletion(root, q);
    int y = p->data;
    p->data = x;
    return y;
}
Node *Binary_Search(Node *&root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return root;
        }
        if (root->data < x)
        {
            root = root->right;
        }
        else
            root = root->left;
    }
    return NULL;
}
int main()
{
    Node *root = NULL;
    InsertBinary_Search_tree(root, 500);
    InsertBinary_Search_tree(root, 800);
    InsertBinary_Search_tree(root, 850);
    InsertBinary_Search_tree(root, 700);
    InsertBinary_Search_tree(root, 600);
    InsertBinary_Search_tree(root, 200);
    InsertBinary_Search_tree(root, 10);
    InsertBinary_Search_tree(root, 20);
    InorderTraversal(root);
    cout << "\n";
    deletion(root, root->left);
    deletion(root, root->left->right);
    InorderTraversal(root);
}
