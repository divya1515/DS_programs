#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertbeg(Node *&head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->prev = temp;
        temp->next = temp;
        head = temp;
    }
    else
    {
        Node *p = head;
        Node *q = p->prev;
        q->next = temp;
        temp->prev = q;
        temp->next = p;
        p->prev = temp;
        head = temp;
    }
}
void insertend(Node *&head, int x)
{
    if (head == NULL)
    {
        insertbeg(head, x);
        return;
    }
    Node *temp = new Node(x);
    Node *p = head;
    Node *q = p->prev;
    q->next = temp;
    temp->prev = q;
    temp->next = p;
    p->prev = temp;
    head = p;
}
void insertAfter(Node *&head, Node *p, int x)
{ // p q r(insertion after p)
    if (p == NULL)
    {
        insertbeg(head, x);
        return;
    }
    Node *q = new Node(x);
    Node *r = p->next;
    r->prev = q;
    q->next = r;
    q->prev = p;
    p->next = q;
}
void insertBefore(Node *&head, Node *p, int x)
{ // r q p
    if (p == NULL || p == head)
    {
        insertbeg(head, x);
        return;
    }
    Node *q = new Node(x);
    Node *r = p->prev;
    r->next = q;
    q->prev = r;
    q->next = p;
    p->prev = q;
}
int deleteBeg(Node *&head)
{
    if (head == NULL)
    {
        printf("Void deleation \n");
        return -1;
    }
    else
    {
        Node *p = head;
        int x = p->data;
        if (p->next == p)
        {
            head = NULL;
        }
        else
        {
            Node *r = p->prev;
            Node *q = p->next;
            q->prev = r;
            r->next = q;
            head = q;
        }
        delete p;
        return x;
    }
}
int deletelast(Node *&head)
{
    if (head == NULL)
    {
        printf("Void deleation \n");
        return -1;
    }
    else
    {
        Node *p = head->prev;
        int x = p->data;
        if (p->next == p)
        {
            delete p;
            head = NULL;
            return -1;
        }
        Node *q = p->prev;
        q->next = head;
        head->prev = q;
        delete p;
        return x;
    }
}
int deleteBefore(Node *&head, Node *p)
{
    // r q p
    if (p == NULL)
    {
        cout << "Void deleation :"
             << "\n";
        return -1;
    }
    if (p == head)
    {
        deletelast(head);
        return -1;
    }
    Node *q = p->prev;
    int x = q->data;
    if (q == head)
    {
        deleteBeg(head);
        return -1;
    }
    Node *r = q->prev;
    r->next = p;
    p->prev = r;
    delete q;
    return x;
}
int deleteAfter(Node *&head, Node *p)
{ // p q r
    if (p == NULL || p->next == p)
    {
        printf("Void deletion \n");
        return -1;
    }
    else
    {
        if (p->next == head)
        {
            deleteBeg(head);
            return -1;
        }
        Node *q;
        q = p->next;
        int x = q->data;
        if (q->next == head)
        {
            p->next = head;
        }
        else
        {
            Node *r;
            r = q->next;
            p->next = r;
            r->prev = p;
        }
        delete q;
        return x;
    }
}
void traverse(Node *&head)
{
    Node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    cout << endl;
}
int main()
{
    Node *head;
    head = NULL;
    insertend(head, 10);
    insertend(head, 20);
    insertend(head, 30);
    printf("Linked list \n");
    traverse(head);
    Node *p = head;
    int d;
    cin >> d; // position after which we want to delete or (before insert) or before which we need to delete or (after insert)
    if (d == 0)
        p = NULL;
    for (int i = 1; i < d; i++)
    {
        p = p->next;
    }
    deleteBefore(head, p);
    printf("Final linked list \n");
    traverse(head);
}
