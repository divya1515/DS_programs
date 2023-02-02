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
int height(Node *&root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
void Zig_Zag(Node *&root)
{
    int h=height(root);
    vector<int>zig[h+1];
   Node *p=root;
   queue<Node*>q;
   q.push(p);
   q.push(NULL);
   int i=0;
   while(!q.empty())
   {
      Node *x=q.front();
      q.pop();
      if(x==NULL)
      {
        if(!q.empty())
        q.push(NULL);
        i++;
      }
      else
      {
         zig[i].push_back(x->data);
         if(x->left!=NULL)
           q.push(x->left);
         if(x->right!=NULL)
           q.push(x->right);
      }
   }
   for(int p=0;p<=h;p++)
   {
      if(p&1)
      {
        for(int j=zig[p].size()-1;j>=0;j--)
        {
            cout<<zig[p][j]<<" ";
        }
      }
      else
      {
        for(int j=0;j<zig[p].size();j++)
        {
            cout<<zig[p][j]<<" ";
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
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(8);
    Zig_Zag(root);
}
