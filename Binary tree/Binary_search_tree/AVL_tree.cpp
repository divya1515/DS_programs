#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        height = 0;
    }
};
Node *Left_Rotation(Node *x)
{
    Node *y = x->right;
    Node *z = y->left;
    y->left = x;
    x->right = z;
    return y;
}
Node *Right_Rotation(Node *x)
{
    Node *y = x->left;
    Node *z = y->right;
    y->right = x;
    x->left = z;
    return y;
}
Node *LL_Rotate(Node *x)
{
    Node *y = Right_Rotation(x);
    return y;
}
Node *RR_Rotate(Node *x)
{
    Node *y = Left_Rotation(x);
    return y;
}
Node *LR_Rotate(Node *x)
{
    Node *y = x->left;
    Node *z = Left_Rotation(y);
    x->left = z;
    Node *t = Right_Rotation(x);
    return t;
}
Node *RL_Rotate(Node *x)
{
    Node *y = x->right;
    Node *z = Right_Rotation(y);
    x->right = z;
    Node *t = Left_Rotation(x);
    return t;
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
int Height(Node *t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
    {
        return 0;
    }
    else
    {
        int hl = Height(t->left);
        int hr = Height(t->right);
        return 1 + max(hl, hr);
    }
}
int Balanced_factor(Node *t)
{
    if (t == NULL)
        return 0;
    int hl = 0, hr = 0;
    if (t->left == NULL)
    {
        hl = 0;
    }
    else
        hl = 1 + t->left->height;
    if (t->right == NULL)
    {
        hr = 0;
    }
    else
        hr = 1 + t->right->height;
    return (hl - hr);
}
Node *AVL_Insert(Node *&t, int x)
{
    if (t == NULL)
    {
        t = new Node(x);
        t->height = Height(t);
        return t;
    }
    if (x < t->data)
    {
        t->left = AVL_Insert(t->left, x);
        if (Balanced_factor(t) == 2)
        {
            if (x < t->left->data)
            {
                t = LL_Rotate(t);
            }
            else
                t = LR_Rotate(t);
        }
    }
    else
    {
        t->right = AVL_Insert(t->right, x);
        if (Balanced_factor(t) == -2)
        {
            if (x >= t->right->data)
            {
                t = RR_Rotate(t);
            }
            else
                t = RL_Rotate(t);
        }
    }
    t->height = Height(t);
    return t;
}
void Level_order_traversal(Node *root)
{
    queue<Node *> q;
    Node *p = root;
    q.push(p);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    AVL_Insert(root, 35);
    AVL_Insert(root, 12);
    AVL_Insert(root, 2);
    AVL_Insert(root, 1);
    AVL_Insert(root, 30);
    AVL_Insert(root, 25);
    AVL_Insert(root, 9);
    AVL_Insert(root, 6);
    AVL_Insert(root, 5);
    AVL_Insert(root, 20);
    InorderTraversal(root);
    cout << endl;
    Level_order_traversal(root);
}
