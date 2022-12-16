#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   char data;
   Node *next;
   Node(char data)
   {
      this->data = data;
      this->next = NULL;
   }
};
void InsertAtHead(Node *&head, char d)
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
void InsertAtTail(Node *&head, char d)
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
void InsertAfter(Node *head, Node *p, char d)
{
   if (p == NULL)
   {
      InsertAtHead(head, d);
   }
   else
   {
      Node *q = new Node(d);
      if (p->next != NULL)
      {
         Node *r = p->next;
         q->next = r;
      }
      p->next = q;
   }
}
char deleteBeg(Node *&head)
{
   Node *p;
   p = head;
   char x = p->data;
   head = p->next;
   delete p;
   return x;
}
char deleteEnd(Node *&head)
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
   char val = p->data;
   delete p;
   q->next = NULL;
   return val;
}
char deleteAfter(Node *p)
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
   char x = q->data;
   r = q->next;
   p->next = r;
   delete q;
   return x;
}
void Arrange_vowels_before_consonants(string s)
{
   Node *head = NULL;
   for (int i = 0; i < s.length(); i++)
   {
      InsertAtTail(head, s[i]);
   }
   Node *p;
   Node *q = NULL;
   Node *r = NULL;
   p = head;
   while (p != NULL && p->data == 'a' || p->data == 'e' || p->data == 'i' || p->data == 'o' || p->data == 'u')
   {
      q = p;
      p = p->next;
   }
   r = p;
   while (p != NULL)
   {
      if (p->data == 'a' || p->data == 'e' || p->data == 'i' || p->data == 'o' || p->data == 'u')
      {
         if (q == NULL)
         {
            InsertAtHead(head, p->data);
            q = head;
            p = p->next;
         }
         else
         {
            InsertAfter(head, q, p->data);
            q = q->next;
            p = p->next;
         }
         deleteAfter(r);
      }
      else
      {
         r = p;
         p = p->next;
      }
   }
   print(head);
}
int main()
{
   string s;
   cin >> s;
   Arrange_vowels_before_consonants(s);
}
