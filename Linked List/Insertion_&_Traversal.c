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
   p = start;
   while (p != NULL)
   {
      printf("%d  ", p->info);
      p = p->next;
   }
   printf("\n");
}
int count(struct node *start)
{
   int c = 0;
   struct node *p;
   p = start;
   while (p != NULL)
   {
      c++;
      p = p->next;
   }
   return c;
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
int main()
{
   struct node *start;
   start = NULL;
   InsertBeg(&start, 200);
   InsertBeg(&start, 300);
   InsertBeg(&start, 400);
   InsertBeg(&start, 500);
   InsertBeg(&start, 600);
   Insertend(&start, 10);
   Insertend(&start, 20);
   Insertend(&start, 30);
   printf("Linked list before insertion\n");
   traverse(start);
   struct node *p = start;
   int d;
   scanf("%d", &d); // position at which the no. to be inserted
   int c = count(start);
   int flag = 0;
   if (d == 1)
   {
      InsertBeg(&start, 67);
   }
   else if (d > c + 1)
   {
      printf("Void Insertion\n");
      flag = 1;
   }
   else
   {
      for (int i = 1; i < d - 1; i++)
      {
         p = p->next;
      }
      InsertAfter(p, 67); // no. to be inserted is 67
   }
   if (flag == 0)
   {
      printf("Linked list after insertion\n");
      traverse(start);
   }
}
