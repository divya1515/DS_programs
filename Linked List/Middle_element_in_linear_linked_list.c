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
void traverse(struct node *start)
{
   struct node *p;
   int c = 0;
   p = start;
   while (p != NULL)
   {
      printf("%d  ", p->info);
      p = p->next;
      c++;
   }
   printf("\nNo. of nodes %d", c);
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
void Cycle_detection(struct node **start)
{
   struct node *t;
   struct node *r;
   t = *start;
   r = *start;
   int flag = 0;
   while (r != NULL && r->next != NULL)
   {
      t = t->next;
      r = r->next;
      r = r->next;
      if (t == r)
      {
         flag = 1;
         break;
      }
   }
   t = *start;
   if (flag == 1)
   {
      while (t != r)
      {
         t = t->next;
         r = r->next;
      }
      printf("Starting value of cycle is: %d\n", t->info);
   }
   else
      printf("Not a Cycle");
}
void Conacat(struct node **start1, struct node **start2)
{
   struct node *p;
   p = *start1;
   while (p->next != NULL)
   {
      p = p->next;
   }
   p->next = *start2;
}
int Middle_element(struct node **start)
{
   struct node *t;
   struct node *r;
   t = *start;
   r = (*start)->next;
   while (r != NULL && r->next != NULL)
   {
      t = t->next;
      r = r->next;
      r = r->next;
   }
   return (t->info);
}
int main()
{
   struct node *start;
   struct node *start1;
   start = NULL;
   InsertBeg(&start, 200);
   Insertend(&start, 300);
   Insertend(&start, 400);
   Insertend(&start, 500);
   Insertend(&start, 600);
   Insertend(&start, 700);

   traverse(start);
   printf("Middle element: %d", Middle_element(&start));
}
