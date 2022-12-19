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
Node *Build_tree(string Inorder, string Postorder, int &index, int inorder_start, int inorder_end)
{
  
  if (index <0 || inorder_start > inorder_end)
  {
    return NULL;
  }
  char element = Postorder[index--];
  Node *root = new Node(element);
  int pos = Search_pos(Inorder, element);
   root->right = Build_tree(Inorder, Postorder, index, pos + 1, inorder_end); // in case of post order we first built right subtree
  root->left = Build_tree(Inorder, Postorder, index, inorder_start, pos - 1);
  return root;
}
void PreorderTraversal(Node *&root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}
int main()
{
  string inOrder, postOrder;
  cin >> inOrder >> postOrder;
  int index = postOrder.length()-1;
  int inorder_start = 0, inorder_end = inOrder.length() - 1;
  Node *x = Build_tree(inOrder, postOrder, index, inorder_start, inorder_end);
  PreorderTraversal(x);
}
