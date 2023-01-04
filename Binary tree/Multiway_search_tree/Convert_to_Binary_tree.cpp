#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *child;
    Node *sibling;
    Node *left;
    Node *right;
    Node(char data)
    {
        this->data = data;
        this->child = NULL;
        this->sibling = NULL;
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
        InorderTraversal(root->child);
        cout << root->data << " ";
        InorderTraversal(root->sibling);
    }
}
void PostorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        PostorderTraversal(root->child);
        PostorderTraversal(root->sibling);
        cout << root->data << " ";
    }
}
void CreateTree(Node *&root)
{
    int choice;

    cout << "Whether The Child of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Child of " << root->data << ": ";
        char x;
        cin >> x;

        Node *n = new Node(x);
        root->child = n;

        CreateTree(n);
    }

    cout << "Whether The Sibling of " << root->data << " Exist(1/0): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Data For Sibling of " << root->data << ": ";
        char x;
        cin >> x;

        Node *n = new Node(x);
        root->sibling = n;

        CreateTree(n);
    }
}
Node *Convert_into_BinaryTree(Node *&root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = root->child;
    root->right = root->sibling;
    Convert_into_BinaryTree(root->left);
    Convert_into_BinaryTree(root->right);
    return root;
}
void Level_order_traversal(Node *&root)
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
    Node *root = new Node('A');
    CreateTree(root);
    Node *x = Convert_into_BinaryTree(root);
    cout << "PreorderTraversal: "
         << "\n";
    PreorderTraversal(x);
    cout << "Level order Traversal: "
         << "\n";
    Level_order_traversal(x);
    cout << endl;
}
