#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int precd(char a, char b)
{
    if (a == '(' || b == '(')
        return 0;
    if (a != '(' && b == ')')
        return 1;
    else if (a == '(' && b == ')')
        return 0;
    else if (a == '^' || a == '*' || a == '%' || a == '/')
    {
        if (b == '^')
            return 0;
        else
            return 1;
    }
    else
    {
        if (b == '+' || b == '-')
            return 1;
        else
            return 0;
    }
}
Node* Build_Expression_Tree(string s)
{
   stack<char>oprator;
   stack<Node*>opndStack;
   int i=0;
   Node *t=NULL;
   while(s[i]!='\0')
   {
       if('a'<=s[i] && s[i]<='z')
       {
           Node *x=new Node(s[i]);
           opndStack.push(x);
       }
       else
       {
          while(!oprator.empty() && precd(oprator.top(),s[i]))
          {
             char op=oprator.top();
             oprator.pop();
             t=new Node(op);
             Node *b=opndStack.top();
             opndStack.pop();
             Node *a=opndStack.top();
             opndStack.pop();
             t->left=a;
             t->right=b;
              opndStack.push(t);
          }
          oprator.push(s[i]);
       }
       i++;
   }
    while(!oprator.empty())
        {
            char op=oprator.top();
             oprator.pop();
             t=new Node(op);
             Node *b=opndStack.top();
             opndStack.pop();
             Node *a=opndStack.top();
             opndStack.pop();
             t->left=(a);
             t->right=(b);
              opndStack.push(t);
        }
        return opndStack.top();
}
void InorderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    if (root != NULL)
    {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
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
   string s;
   cin>>s;
   Node *x=Build_Expression_Tree(s);
   InorderTraversal(x);
   cout<<"\n";
   PreorderTraversal(x);
}
