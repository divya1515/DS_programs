#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
  char data;
  Node *left;
  Node *right;
  Node(char data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};
int Search_pos(string Inorder, char x)
{
  for (int i = 0; i < Inorder.length(); i++)
  {
    if (Inorder[i] == x)
    {
      return i;
    }
  }
  return -1;
}
Node *Build_tree(string Inorder, string Preorder, int &index, int inorder_start, int inorder_end, int n)
{
  if (index >= n || inorder_start > inorder_end)
  {
    return NULL;
  }
  char element = Preorder[index++];
  Node *root = new Node(element);
  int pos = Search_pos(Inorder, element);
  root->left = Build_tree(Inorder, Preorder, index, inorder_start, pos - 1, n);
  root->right = Build_tree(Inorder, Preorder, index, pos + 1, inorder_end, n);
  return root;
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
int main()
{
  string inOrder, preOrder;
  cin >> inOrder >> preOrder;
  int index = 0;
  int inorder_start = 0, inorder_end = inOrder.length() - 1;
  Node *x = Build_tree(inOrder, preOrder, index, inorder_start, inorder_end, preOrder.length());
  PostorderTraversal(x);
}
