#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void  Left_view_traversal(Node *&root)
{
    queue<Node *> q;
    Node *p = root;
    q.push(p);
    if(p!=NULL)
    {
        cout<<q.front()->data;
    }
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!q.empty())
            {
                cout<<q.front()->data;
                q.push(NULL);
            }
        }
        else
        {
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Left_view_traversal(root);
}
