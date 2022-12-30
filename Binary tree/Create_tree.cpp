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
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}
void PostorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
}
void CreateTree(Node *&root)
{
     int ch;
   cout<<"Enter choice whether left of "<<root->data<<" exist or not(1/0)"<<"\n";
   cin>>ch;//if left node exist then ch=1 else ch=0
   if(ch==1)
   {
      cout<<"Enter left data for "<<root->data<<": ";
      int d;
      cin>>d;
      root->left=new Node(d);
      CreateTree(root->left);
   }
   cout<<"Enter choice whether right of "<<root->data<<" exist or not(1/0)"<<"\n";
   cin>>ch;//if right node exist then ch=1 else ch=0
   if(ch==1)
   {
     cout<<"Enter right data for "<<root->data<<": ";
     int d;
     cin>>d;
     root->right=new Node(d);
     CreateTree(root->right);
   }

}
int main()
{
    Node *root = new Node(1);
    CreateTree(root);
    cout<<"PreorderTraversal: "<<"\n";
    PreorderTraversal(root);
    cout<<endl;
    cout<<"InorderTraversal: "<<"\n";
    InorderTraversal(root);
    cout<<endl;
    cout<<"PostorderTraversal: "<<"\n";
    PostorderTraversal(root);
    cout<<endl;
}
