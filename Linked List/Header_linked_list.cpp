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
void InsertAfter(Node *&head, Node *p, int d, Node *&root)
{
    Node *q = new Node(d);
    if (p->next != NULL)
    {
        Node *r = p->next;
        q->next = r;
    }
    p->next = q;
    head = root->next;
    root->data++;
}
void InsertAtHead(Node *&root, Node *&head, int d)
{
    InsertAfter(head, root, d, root);
}
void print(Node *&root, Node *&head)
{
    if (root->data == 0)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    Node *p;
    p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "Total nodes :" << root->data << endl;
    cout << endl;
}
void InsertAtTail(Node *&root, Node *&head, int d)
{
    if (head == NULL)
    {
        InsertAtHead(root, head, d);
        return;
    }
    Node *p = head;
    Node *temp = new Node(d);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    head = root->next;
    root->data++;
}
int deleteBeg(Node *&root, Node *&head)
{
    if (head == NULL)
    {
        cout << "Void deleation" << endl;
        return -1;
    }
    Node *p;
    root->next = head->next;
    p = head;
    int x = p->data;
    delete p;
    head = root->next;
    root->data--;
    return x;
}
int deleteEnd(Node *&root, Node *&head)
{
    if (head == NULL)
    {
        cout << "Void deleation" << endl;
        return -1;
    }
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
    if (q != NULL)
        q->next = NULL;
    else
        head = NULL;
    root->data--;
    return val;
}
int deleteAfter(Node *&head, Node *p, Node *&root)
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
    root->data--;
    return x;
}
int main()
{
    Node *root = new Node(0);
    Node *head = root->next;
    InsertAtTail(root, head, 3);
    InsertAtTail(root, head, 8);
    InsertAtTail(root, head, 7);
    InsertAtTail(root, head, 9);
    int d;
    cin >> d;
    Node *p;
    p = head;
    for (int i = 1; i < d; i++)
    {
        p = p->next;
    }
    print(root, head);
    deleteAfter(head, p, root);
    deleteEnd(root, head);
    deleteEnd(root, head);
    print(root, head);
}
