#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(node* &head ,int d)
{
  node *temp=new node(d);
  temp->next=head;
  head=temp;
}
void InsertAtTail(node* &head,int d)
{
    if(head==NULL)
    {
        InsertAtHead(head,d);
        return;
    }
    node *p=head;
    node *temp=new node(d);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
}
void print(node *&head)
{
    node *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    node *Ht[15];
    for(int i=0;i<15;i++)
    {
        Ht[i]=NULL;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int r=x%10;
        InsertAtTail(Ht[r],x);  
    }
    for(int i=1;i<15;i++)
    {
        cout<<i<<": ";
        print(Ht[i]);
        cout<<endl;
    }
}
