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
int count(Node *&head)
{
    Node *p;
    p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
Node *Middle_element(Node *&head)
{
    Node *t = head;
    Node *r = head->next;
    while (r != NULL && r->next != NULL)
    {
        t = t->next;
        r = r->next;
        r = r->next;
    }
    return t;
}
Node *Binary_search(Node *&head, int x)
{
    Node *p = head;
    Node *m;
    while (p->next != NULL)
    {
        m = Middle_element(head);
        if (m->data == x)
        {
            return m;
        }
        else if (x < m->data)
        {
            m->next = NULL;
        }
        else
            head = m;
    }
    if (m->data == x)
        return m;
    else
        return NULL;
}
int main()
{
    Node *head;
    head = NULL;
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
    int val;
    cin >> val;
    cout << Binary_search(head, val) << "\n";
}
