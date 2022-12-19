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
      this->father=NULL;
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
      p->left->father=p;
   }
   else
   {
      p->right = new Node(x);
      p->right->father=p;
   }
}
Node *Binary_Search(Node *&root,int x)
{
   while(root!=NULL)
   {
   if(root->data==x)
   {
      return root;
   }
   if(root->data <x)
   {
      root=root->right;
   }
   else
     root=root->left;
   }
   return NULL;
} 
Node* Maximum(Node *&root)
{
   Node *p=root;
   while(p->right!=NULL)
   {
      p=p->right;
   }
   return p;
}
void Predeccessor(Node *p)
{
   Node *q;
  if(p->left!=NULL)
  {
     q=Maximum(p->left);
  }
  else
  {
    q=p->father;
     while(q!=NULL && q->left==p)
     {
       p=q;
       q=q->father;
     }
  }
  cout<<q->data;
}
int main()
{
   Node *root = NULL;
   InsertBinary_Search_tree(root, 500);
   InsertBinary_Search_tree(root, 200);
   InsertBinary_Search_tree(root, 10);
   InsertBinary_Search_tree(root, 20);
   InsertBinary_Search_tree(root, 60);
   InsertBinary_Search_tree(root, 300);
   InorderTraversal(root);
   cout<<endl;
   int x;
   cin>>x;
   Node *f=Binary_Search(root,x);
   Predeccessor(f);
}
