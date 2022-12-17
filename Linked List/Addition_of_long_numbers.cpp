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
        cout << p->data;
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
Node *add_of_two_linkedlist(Node *&head1, Node *&head2)
{

    Node *head3 = NULL;
    Node *p;
    Node *q;
    p = head1;
    q = head2;
    int carry = 0;
    int sum, total;
    while (p != NULL && q != NULL)
    {
        total = p->data + q->data + carry;
        sum = total % 10000;
        carry = total / 10000;
        p = p->next;
        q = q->next;
        InsertAtHead(head3, sum);
    }
    while (p != NULL)
    {
        total = p->data + carry;
        sum = total % 10000;
        carry = total / 10000;
        InsertAtHead(head3, sum);
        p = p->next;
    }
    while (q != NULL)
    {
        total = q->data + carry;
        sum = total % 10000;
        carry = total / 10000;
        InsertAtHead(head3, sum);
        q = q->next;
    }
    if (carry > 0)
        InsertAtHead(head3, carry);
    return head3;
}
void Addition_of_longNo(string s1, string s2)
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int i, x;

    // 123456789 -> linkedlist:  6789 2345 1

    for (i = s1.length() - 4; i >= 0; i = i - 4)
    {
        x = stoi(s1.substr(i, 4));
        InsertAtTail(head1, x);
    }
    if (-4 < i && i < 0)
    {
        x = stoi(s1.substr(0, 4 + i));
        InsertAtTail(head1, x);
    }
    int j;
    for (j = s2.length() - 4; j >= 0; j = j - 4)
    {
        InsertAtTail(head2, (stoi(s2.substr(j, 4))));
    }
    if (-4 < j && j < 0)
        InsertAtTail(head2, (stoi(s2.substr(0, 4 + j))));
    Node *f = add_of_two_linkedlist(head1, head2); // logic for addition of two linkedlist
    // suppose 00005 + 90000 -->it will give 905 but the answer is 90005
    // thus to add zeros in front of any linkedlist node if length is less than 4
    string ans = "";
    string s;
    while (f != NULL)
    {
        s = to_string(f->data);
        if (s.length() < 4)
        {
            string s1(4 - s.length(), '0');
            s.insert(0, s1);
        }
        ans += s;
        f = f->next;
    }

    // now for removing prezeros
    string res = "";
    int k = 0;
    while (ans[k] == '0')
    {
        k++;
    }
    while (k < ans.length())
    {
        res += ans[k];
        k++;
    }
    cout << res;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Addition_of_longNo(s1, s2);
}
