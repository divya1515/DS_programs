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
void Initialize(Node *&rear, Node *&front)
{
    rear = NULL;
    front = NULL;
}
void push_front(Node *&rear, Node *&front, int x)
{
    Node *temp = new Node(x);
    if (front == NULL)
    {
        front = temp;
        rear = front;
        return;
    }
    temp->next = front;
    front = temp;
}
void push_back(Node *&rear, Node *&front, int x)
{
    Node *temp = new Node(x);
    if (rear == NULL)
    {
        rear = temp;
        front = rear;
        return;
    }
    rear->next = temp;
    temp->prev = rear;
    rear = temp;
}
void pop_front(Node *&rear, Node *&front)
{
    if (front == NULL)
    {
        cout << "Void deleation\n";
        return;
    }
    Node *s = front;
    if (front->next == NULL)
    {
        front = NULL;
        return;
    }
    Node *p = front->next;
    p->prev = NULL;
    front = p;
    delete s;
}
void pop_back(Node *&rear, Node *&front)
{
    Node *s = rear;
    if (rear == NULL)
    {
        cout << "Void deleation\n";
        return;
    }
    if (rear->prev == NULL)
    {
        rear = NULL;
        delete s;
        return;
    }
    Node *p = rear->prev;
    p->next = NULL;
    rear = p;
    delete s;
}
int IsEmpty(Node *&front, Node *&rear)
{
    if (front == NULL)
        return 1;
    return 0;
}
int Front(Node *&front, Node *&rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue empty\n";
        return -1;
    }
    return front->data;
}
int Rear(Node *&front, Node *&rear)
{
    if (IsEmpty(front, rear))
    {
        cout << "Queue empty\n";
        return -1;
    }
    else
        return rear->data;
}
void traverse(Node *&front, Node *&rear)
{
    if (rear == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
int main()
{
    Node *rear;
    Node *front;
    Initialize(rear, front);
    push_back(rear, front, 56);
    push_back(rear, front, 55);
    push_back(rear, front, 54);
    traverse(front, rear);
    pop_back(rear, front);
    cout << Rear(front, rear) << "\n";
    traverse(front, rear);
}
