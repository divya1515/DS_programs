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
    Node *p = head;
    Node *q = new Node(x);
    q->prev = NULL;
    if (p != NULL)
    {
        p->prev = q;
        q->next = p;
    }
    else
        q->next = NULL;
    head = q;
}
void insertend(Node *&head, int x)
{
    Node *p = head;
    Node *q = new Node(x);
    q->next = NULL;
    if (p != NULL)
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        q->prev = p;
        p->next = q;
    }
    else
    {
        q->prev = NULL;
        head = q;
    }
}
void insertAfter(Node *&head, Node *p, int x)
{ // p q r(insertion after p)
    if (p == NULL)
    {
        insertbeg(head, x);
    }
    else
    {
        Node *q = new Node(x);
        Node *r;
        if (p->next == NULL)
        {
            q->prev = p;
            p->next = q;
            q->next = NULL;
        }
        else
        {
            r = p->next;
            q->next = r;
            r->prev = q;
            q->prev = p;
            p->next = q;
        }
    }
}
void insertBefore(Node *&head, Node *p, int x)
{ // r q p
    if (p == NULL)
    {
        insertbeg(head, x);
    }
    else
    {
        Node *q = new Node(x);
        if (p->prev == NULL)
        {
            q->prev = NULL;
            q->next = p;
            p->prev = q;
            head = q;
        }
        else
        {
            Node *r;
            r = p->prev;
            r->next = q;
            q->prev = r;
            q->next = p;
            p->prev = q;
        }
    }
}
int deleteBeg(Node *&head)
{
    if (head == NULL)
    {
        printf("Void deleation \n");
    }
    else
    {
        Node *p = head;
        int x = p->data;
        Node *q;
        q = p->next;
        delete p;
        if (p->next != NULL)
        {
            q->prev = NULL;
            head = q;
        }
        else
            head = NULL;
        return x;
    }
}
int deletelast(Node *&head)
{
    if (head == NULL)
    {
        printf("Void deleation \n");
    }
    else
    {
        Node *p = head;
        Node *q;
        while (p->next != NULL)
        {
            p = p->next;
        }
        int x = p->data;
        if (p->prev != NULL)
        {
            q = p->prev;
            delete p;
            q->next = NULL;
        }
        else
        {
            delete p;
            head = NULL;
        }
        return x;
    }
}
int deleteBefore(Node *&head, Node *p)
{
    if (p == NULL || p->prev == NULL)
    {
        printf("Void deletion \n");
        return -1;
    }
    else
    {
        Node *q;
        q = p->prev;
        int x = q->data;
        if (q == head)
        {
            p->prev = NULL;
            head = p;
        }
        else
        {
            Node *r;
            r = q->prev;
            r->next = p;
            p->prev = r;
        }
        delete q;
        return x;
    }
}
int deleteAfter(Node *&head, Node *p)
{
    if (p == NULL || p->next == NULL)
    {
        printf("Void deletion \n");
        return -1;
    }
    else
    {
        Node *q;
        q = p->next;
        int x = q->data;
        if (q->next == NULL)
        {
            p->next = NULL;
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
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node *head;
    head = NULL;
    insertend(head, 10);
    insertend(head, 20);
    insertend(head, 30);
    insertend(head, 40);
    insertend(head, 50);
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
    insertAfter(head, p, 4);
    printf("Final linked list \n");
    traverse(head);
}
