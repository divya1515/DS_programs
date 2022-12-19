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
   }
   else
   {
      p->right = new Node(x);
   }
}
void Minimum(Node *&root)
{
   Node *p=root;
   while(p->left!=NULL)
   {
      p=p->left;
   }
   cout<<p->data<<"\n";
}
void Maximum(Node *&root)
{
   Node *p=root;
   while(p->right!=NULL)
   {
      p=p->right;
   }
   cout<<p->data;
}
int main()
{
   Node *root = NULL;
   int x;
   cin >> x;
   InsertBinary_Search_tree(root, 500);
   InsertBinary_Search_tree(root, 200);
   InsertBinary_Search_tree(root, 10);
   InsertBinary_Search_tree(root, 20);
   Minimum(root);
   Maximum(root);
}
