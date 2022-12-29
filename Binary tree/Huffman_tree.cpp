#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node *next;
    int freq;
    Node()
    {
        this->data = '\0';
        this->left = NULL;
        this->right = NULL;
        this->freq = 0;
        next = NULL;
    }
};
void Level_order_traversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        if (p != NULL)
        {
            cout << p->freq << " ";

            if (p->left != NULL)
            {
                q.push(p->left);
            }

            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
void Pq_insert(Node *&root, Node *&p)
{
    Node *s = root;
    Node *r = NULL;
    while (s != NULL && s->freq <= p->freq)
    {
        r = s;
        s = s->next;
    }
    if (r == NULL)
    {
        p->next = root;
        root = p;
    }
    else
    {
        Node *t = r->next;
        r->next = p;
        if (t != NULL)
        {
            p->next = t;
        }
        else
            p->next = NULL;
    }
}
Node *pq_delete(Node *&root) // no need to delete any node from memory because we will have its use furthur therefore we will not used delete p 
{
    Node *p;
    p = root;  
    root = root->next; // only shifting the root
    return p;  
}
void print(Node *&root)
{
    Node *p;
    p = root;
    while (p != NULL)
    {
        cout << p->data << " " << p->freq;
        cout << "\n";
        p = p->next;
    }
    cout << endl;
}
Node *Huffman_tree(char arr[], int freq[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *p = new Node();
        p->data = arr[i];
        p->freq = freq[i];
        Pq_insert(root, p); // pq is priority queue implemented through (ordered insertion in linked list)ascending _order_insertion
    }
    int i = 1;
    while (i < n)
    {
        Node *a = pq_delete(root);
        Node *b = pq_delete(root);
        Node *t = new Node();
        t->freq = a->freq + b->freq;
        t->left = a;
        t->right = b;
        Pq_insert(root, t);
        i++;
    }
    return pq_delete(root);
}
int main()
{
    int n;
    cin >> n;
    int freq[n];
    char arr[n]; // arr contains the characters and freq contains the frequency of every character
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }
    Node *root = Huffman_tree(arr, freq, n);
    Level_order_traversal(root);
}
