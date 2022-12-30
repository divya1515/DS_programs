#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *child;
    Node *sibling;
    Node(char data)
    {
        this->data = data;
        this->child = NULL;
        this->sibling = NULL;
    }
};
void PreorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreorderTraversal(root->child);
        PreorderTraversal(root->sibling);
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
int main()
{
    Node *root = new Node('A');
    CreateTree(root);
    cout<<"PreorderTraversal: "<<"\n";
    PreorderTraversal(root);
    cout<<endl;
}
