#include<stdlib.h>
#include<stdio.h>
struct node{
  int info;
  struct node *next;
};
struct node *GetNode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void InsertBeg(struct node **start,int x)
{
    struct node *p;
    p=GetNode();
    p->info=x;
    p->next=*start;
    *start=p;
}
void Insertend(struct node **start,int x)
{
   struct node *q;
   q=*start;
   while(q->next!=NULL)
   {
    q=q->next;
   }
   struct node *p;
   p=GetNode();
   p->info=x;
   p->next=NULL;
   q->next=p;
}
void traverse(struct node *start)
{
   struct node *p;
   int c=0;
   p=start;
   while(p!=NULL)
   {
    printf("%d  ",p->info);
    p=p->next;
    c++;
   }
   printf("\nNo. of nodes %d",c);
   printf("\n");
}
void InsertAfter(struct node *q,int x)
{
  struct node*r;
  struct node*p;
  r=q->next;
  p=GetNode();
  p->info=x;
  p->next=r;
  q->next=p;
}
int main()
{
   struct node *start;
   start=NULL;
   InsertBeg(&start,200);
   InsertBeg(&start,300);
   InsertBeg(&start,400);
   InsertBeg(&start,500);
   InsertBeg(&start,600);
   Insertend(&start,10);
   Insertend(&start,20);
   Insertend(&start,30);
   printf("Linked list before insertion\n");
   traverse(start);
}
