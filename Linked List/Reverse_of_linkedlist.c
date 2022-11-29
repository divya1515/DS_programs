//inplace
#include <stdlib.h>
#include <stdio.h>
struct node
{
   int info;
   struct node *next;
};
struct node *GetNode()
{
   struct node *p;
   p = (struct node *)malloc(sizeof(struct node));
   return p;
}
void InsertBeg(struct node **start, int x)
{
   struct node *p;
   p = GetNode();
   p->info = x;
   p->next = *start;
   *start = p;
}
void Insertend(struct node **start, int x)
{
   if(*start==NULL)
   {
     InsertBeg(&(*start),x);
   }
   else
   {
   struct node *q;
   q = *start;
   while (q->next != NULL)
   {
      q = q->next;
   }
   struct node *p;
   p = GetNode();
   p->info = x;
   p->next = NULL;
   q->next = p;
   }
}
void traverse(struct node *start)
{
   struct node *p;
   p = start;
   while (p != NULL)
   {
      printf("%d  ", p->info);
      p = p->next;
   }
   printf("\n");
}
void InsertAfter(struct node *q, int x)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = GetNode();
   p->info = x;
   p->next = r;
   q->next = p;
}
void reverse(struct node **start)
{
  struct node *p;
  struct node *c;
  struct node *n;
  p=NULL;
  c=*start;
  n=c->next;
  while(c!=NULL)
  {
     c->next=p;
      p=c;
      c=n;
     if(n!=NULL)
     {
      n=n->next;
     }
  }
  *start=p;
  traverse(*start);
 
}
int main()
{
   struct node *start;
   start = NULL;
   Insertend(&start, 200);
   Insertend(&start, 300);
   Insertend(&start, 400);
   Insertend(&start, 500);
   Insertend(&start, 600);
   Insertend(&start, 10);
   Insertend(&start, 20);
   Insertend(&start, 30);
   printf("Linked list\n");
   traverse(start);
   struct node *rev;
   printf("Reverse Linked list\n");
   reverse(&start);
}
