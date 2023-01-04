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
void Level_order_traversal(Node *&root)
{
    queue<Node *> q;
    Node *p = root;
    q.push(p);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
          cout << temp->data<<" ";
          if(temp->child!=NULL)
          {
            q.push(temp->child);
            Node *p=temp->child->sibling;
            while(p!=NULL)
            {
                q.push(p);
                p=p->sibling;
            }
          }
    }
}
int main()
{
    Node *root = new Node('A');
    CreateTree(root);
    cout<<"Level Order: "<<"\n";
    Level_order_traversal(root);
    cout<<endl;
}
