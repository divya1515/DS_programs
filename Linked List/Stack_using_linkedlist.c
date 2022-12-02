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
int DeleteBeg(struct node **start)
{
   struct node *p;
   if ((*start) == NULL)
   {
      printf("Void deleation\n");
      return -1;
   }
   else
   {
      p = *start;
      int x = p->info;
      *start = p->next;
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
void push(struct node **top, int x)
{
   InsertBeg(&(*top), x);
}
void Initialize(struct node **top)
{
   *top = NULL;
}
int IsEmpty(struct node **top)
{
   if (*top == NULL)
   {
      return 1;
   }
   return 0;
}
int pop(struct node **top)
{
   if (IsEmpty(&(*top)))
   {
      printf("Void Deleation\n");
      return -1;
   }
   int x = DeleteBeg(&(*top));
   return x;
}
int Top(struct node **top)
{

   return (*top)->info;
}

int main()
{
   struct node *top;
   Initialize(&top);
   push(&top, 2);
   push(&top, 3);
   push(&top, 4);
   push(&top, 5);
   pop(&top);
   pop(&top);
   pop(&top);
   pop(&top);
}
