// 988 - 99 = 889
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};
void InsertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}
void print(Node *&head)
{
  Node *p;
  p = head;
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}
void InsertAtTail(Node *&head, int d)
{
  if (head == NULL)
  {
    InsertAtHead(head, d);
    return;
  }
  Node *p = head;
  Node *temp = new Node(d);
  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
}
void InsertAfter(Node *p, int d)
{
  Node *q = new Node(d);
  if (p->next != NULL)
  {
    Node *r = p->next;
    q->next = r;
  }
  p->next = q;
}
int deleteBeg(Node *&head)
{
  Node *p;
  p = head;
  int x = p->data;
  head = p->next;
  delete p;
  return x;
}
int deleteEnd(Node *&head)
{
  Node *p;
  p = head;
  Node *q;
  q = NULL;
  while (p->next != NULL)
  {
    q = p;
    p = p->next;
  }
  int val = p->data;
  delete p;
  q->next = NULL;
  return val;
}
int deleteAfter(Node *p)
{
  Node *q;
  Node *r;
  if (p == NULL || p->next == NULL)
  {
    cout << "Void deletion :"
         << "\n";
    return -1;
  }
  q = p->next;
  int x = q->data;
  r = q->next;
  p->next = r;
  delete q;
  return x;
}
void reverse(Node *&head)
{
  Node *p;
  Node *c;
  Node *n;
  p = NULL;
  c = head;
  n = c->next;
  while (c != NULL)
  {
    c->next = p;
    p = c;
    c = n;
    if (n != NULL)
    {
      n = n->next;
    }
  }
  head = p;
}
Node *Subtraction(Node *&head1, Node *&head2)
{
  reverse(head1);
  reverse(head2);
  Node *p = head1;
  Node *q = head2;
  Node *head3 = NULL;
  int carry = 0;
  int n;
  while (p != NULL && q != NULL)
  {
    int x = p->data - carry;
    if (x < q->data)
    {
      n = (10 + x) - q->data;
      carry = 1;
    }
    else
    {
      n = x - q->data;
      carry = 0;
    }
    InsertAtHead(head3, n);
    p = p->next;
    q = q->next;
  }
  while (p != NULL)
  {
    int x = p->data - carry;
    InsertAtHead(head3, x);
    carry = 0;
    p = p->next;
  }
  return head3;
}
int main()
{
  Node *head1;
  head1 = NULL;
  InsertAtTail(head1, 9);
  InsertAtTail(head1, 8);
  InsertAtTail(head1, 8);
  print(head1);
  Node *head2;
  head2 = NULL;
  InsertAtTail(head2, 9);
  InsertAtTail(head2, 9);
  print(head2);
  Node *head3 = Subtraction(head1, head2);
  print(head3);
}
