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
    Node *p = head;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }
    while (p->next != head)
    {
        p = p->next;
    }
    temp->next = head;
    p->next = temp;
    head = temp;
}
void print(Node *&head)
{
    Node *p;
    p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
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
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = head;
}
void InsertAfter(Node *p, int d)
{
    Node *q = new Node(d);
    Node *r = p->next;
    q->next = r;
    p->next = q;
}
int deleteBeg(Node *&head)
{
    if (head == NULL)
    {
        cout << "Void deleation "
             << "\n";
        return -1;
    }
    Node *t = head;
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    delete t;
}
int deleteEnd(Node *&head)
{
    Node *p = head;
    Node *q;
    while (p->next != head)
    {
        q = p;
        p = p->next;
    }
    q->next = head;
    delete p;
}
int deleteAfter(Node *p, Node *&head)
{
    if (p == NULL)
    {
        deleteBeg(head);
        return -1;
    }
    Node *q;
    q = p->next;
    int x = q->data;
    if (q->next == head)
        p->next = head;

    p->next = q->next;
    delete q;
    return x;
}
Node *Josephus(Node *&head, int k)
{
    Node *p = head;
    Node *q = NULL;
    int i = 1;
    while (p->next != p)
    {
        i = 1;
        while (i != k)
        {
            q = p;
            p = p->next;
            i++;
        }
        p = p->next;
        deleteAfter(q, head);
    }
    return p;
}
int main()
{
    Node *head;
    head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    cout << "Linked list\n";
    print(head);
    int k;
    cin >> k;
    Node *x;
    x = Josephus(head, k);
    cout << x->data << "\n";
}
