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
void Make_Cycle(int x, int y, struct node **start)
{
   struct node *p;
   struct node *q;
   p = *start;
   int c = 1;
   while (c < x)
   {
      p = p->next;
      c++;
   }
   c = 1;
   q = *start;
   while (c < y)
   {
      q = q->next;
      c++;
   }
   q->next = p;
}
void cycle_length(struct node **start)
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
   t = t->next;
   r = r->next->next;
   int count = 1;
   while (t != r)
   {
      t = t->next;
      r = r->next->next;
      count++;
   }
   printf("No. of elements in cyclic node: %d\n", count);
}
int main()
{
   struct node *start;
   start = NULL;
   InsertBeg(&start, 200);
   Insertend(&start, 300);
   Insertend(&start, 400);
   Insertend(&start, 500);
   Insertend(&start, 600);
   Insertend(&start, 700);
   Insertend(&start, 800);
   traverse(start);
   Make_Cycle(2, 7, &start); // 1 based indexing(2 and 7 are indexes in between the cycle should be made)
   Cycle_detection(&start);
   cycle_length(&start);
}
