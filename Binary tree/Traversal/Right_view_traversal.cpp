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
void Right_view_traversal(Node *&root)
{
    queue<Node *> q;
    Node *p = root;
    q.push(p);
   while(!q.empty())
   {
    int n=q.size();
    for(int i=0;i<n;i++)
    {
      Node *temp=q.front();
      q.pop();
      if(i==n-1)
      {
        cout<<temp->data<<" ";
      }
      if(temp->left!=NULL)
      {
        q.push(temp->left);
      }
      if(temp->right!=NULL)
      {
        q.push(temp->right);
      }
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
    Right_view_traversal(root);
}
