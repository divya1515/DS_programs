//merging point or to find intersecting point
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
int Count_nodes(Node *&head)
{
    Node *p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
Node *Merging_node(Node *&head1, Node *&head2)
{
    Node *p = head1;
    Node *q = head2;
    int m = Count_nodes(head1);
    int n = Count_nodes(head2);
    if (m > n)
    {
        for (int i = 1; i < m - n; i++)
        {
            p = p->next;
        }
    }
    else
    {
        for (int i = 1; i < n - m; i++)
        {
            q = q->next;
        }
    }
    while (p != q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main()
{
    Node *head1;
    head1 = NULL;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 2);
    InsertAtTail(head1, 3);
    InsertAtTail(head1, 4);
    InsertAtTail(head1, 5);
    InsertAtTail(head1, 6);
    cout << "First linked list: "
         << "\n";
    print(head1);
    Node *head2;
    head2 = NULL;
    Node *p = head1;
    for (int i = 1; i < 3; i++)
    {
        p = p->next;
    }
    InsertAtTail(head2, 8);
    InsertAtTail(head2, 9);
    Node *q = head2;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    cout << "2nd linked list: "
         << "\n";
    print(head2);
    Node *ans = Merging_node(head1, head2);
    if (ans == NULL)
    {
        cout << "Merging point does not exist\n";
    }
    else
        cout << "Merging point: " << ans->data;
}
