#include <bits/stdc++.h>
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
Node *rear;
Node *front;
void Enqueue(Node* &p)
{
  if(rear==NULL)
  {
    rear=p;
    front=rear;
  }
  else
  {
    rear->next=p;
    rear=p;
  }
}
Node* Dequeue()
{
    Node *p;
     p=front;
    if(rear==front)
    {
        front=NULL;
        rear=NULL; 
    }
    else
   front=front->next;
   return p;
}
int IsEmpty()
{
    if(rear==NULL)
    return 1;
    else
    return 0;
}
void Initialize()
{
    rear=NULL;
    front=NULL;
}
void Level_order_traversal(Node* &root)
{
    Initialize();
   Node*p=root;
   Enqueue(p);
   while(!IsEmpty())
   {
      Node *x=Dequeue();
      cout<<x->data<<" ";
      if(x->left!=NULL)
      {
        Enqueue(x->left);
      }
      if(x->right!=NULL)
      {
        Enqueue(x->right);
      }

   }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
   root->left->left=new Node(4);
   root->left->right=new Node(5);
   root->right->left=new Node(6);
   root->right->right=new Node(7);
    Level_order_traversal(root);
}
