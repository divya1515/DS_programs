#include <stdlib.h>
#include <stdio.h>
#define stacksize 30
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
   if (*start == NULL)
   {
      InsertBeg(&(*start), x);
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
int DeleteBeg(struct node **front)
{
   struct node *p;
   if ((*front) == NULL)
   {
      printf("Void deleation\n");
      return -1;
   }
   else
   {
      p = *front;
      int x = p->info;
      *front = p->next;
      free(p);
      return x;
   }
}
int DeleteEnd(struct node **start)
{
   struct node *q;
   struct node *p;
   q = NULL;
   p = *start;
   while (p->next != NULL)
   {
      q = p;
      p = p->next;
   }
   int x = p->info;
   free(p);
   q->next = NULL;
   return x;
}
int deleteAfter(struct node *p)
{
   struct node *q;
   struct node *r;
   if (p == NULL || p->next == NULL)
   {
      printf("Void deleation\n");
      return -1;
   }
   q = p->next;
   int x = q->info;
   r = q->next;
   p->next = r;
   free(q);
   return x;
}
void Enqueue(struct node **front, struct node **rear, int x)
{
   if (*rear == NULL)
   {
      InsertBeg(&(*rear), x);
      *front = *rear;
   }
   else
   {
      InsertAfter((*rear), x);
      (*rear) = (*rear)->next;
   }
}
void Initialize(struct node **front, struct node **rear)
{
   *front = NULL;
   *rear = NULL;
}
int IsEmpty(struct node **front, struct node **rear)
{
   if (*rear - *front + 1 == 0)
   {
      return 1;
   }
   return 0;
}
int Dequeue(struct node **front, struct node **rear)
{
   if (IsEmpty(&(*front), &(*rear)))
   {
      printf("Void Deleation\n");
      return -1;
   }
   else
   {
      int x = DeleteBeg(&(*front));
      if (*front == NULL)
      {
         *rear = NULL;
      }
      return x;
   }
}
int main()
{
   struct node *front;
   struct node *rear;
   Initialize(&front, &rear);
   Enqueue(&front, &rear, 2);
   Enqueue(&front, &rear, 3);
   Enqueue(&front, &rear, 4);
   Enqueue(&front, &rear, 5);
   traverse(front);
   Dequeue(&front, &rear);
   Dequeue(&front, &rear);
   traverse(front);
}
