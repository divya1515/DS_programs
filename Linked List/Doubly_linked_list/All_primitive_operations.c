#include <stdlib.h>
#include <stdio.h>
struct node
{
   int info;
   struct node *next;
   struct node *prev;
};
struct node *GetNode()
{
   struct node *p;
   p = (struct node *)malloc(sizeof(struct node));
   return p;
}
void insertbeg(struct node **dstart, int x)
{
   struct node *p;
   struct node *q;
   p = *dstart;
   q = GetNode();
   q->info = x;
   q->prev = NULL;
   if (p != NULL)
   {
      p->prev = q;
      q->next = p;
   }
   else
      q->next = NULL;
   *dstart = q;
}
void insertend(struct node **dstart, int x)
{
   struct node *p;
   p = *dstart;
   struct node *q;
   q = GetNode();
   q->info = x;
   q->next = NULL;
   if (p != NULL)
   {
      while (p->next != NULL)
      {
         p = p->next;
      }
      q->prev = p;
      p->next = q;
   }
   else
   {
      q->prev = NULL;
      *dstart = q;
   }
}
void insertAfter(struct node **dstart, struct node *p, int x)
{ // p q r(insertion after p)
   if (p == NULL)
   {
      insertbeg(&(*dstart), x);
   }
   else
   {
      struct node *q;
      q = GetNode();
      q->info = x;
      struct node *r;
      if (p->next == NULL)
      {
         q->prev = p;
         p->next = q;
         q->next = NULL;
      }
      else
      {
         r = p->next;
         q->next = r;
         r->prev = q;
         q->prev = p;
         p->next = q;
      }
   }
}
void insertBefore(struct node **dstart, struct node *p, int x)
{ // r q p
   if (p == NULL)
   {
      insertbeg(&(*dstart), x);
   }
   else
   {
      struct node *q;
      q = GetNode();
      q->info = x;
      if (p->prev == NULL)
      {
         q->prev = NULL;
         q->next = p;
         p->prev = q;
         *dstart = q;
      }
      else
      {
         struct node *r;
         r = p->prev;
         r->next = q;
         q->prev = r;
         q->next = p;
         p->prev = q;
      }
   }
}
int deleteBeg(struct node **dstart)
{
   if (*dstart == NULL)
   {
      printf("Void deleation \n");
   }
   else
   {
      struct node *p;
      p = *dstart;
      int x = p->info;
      struct node *q;
      q = p->next;
      free(p);
      if (p->next != NULL)
      {
         q->prev = NULL;
         *dstart = q;
      }
      else
         *dstart = NULL;
      return x;
   }
}
int deletelast(struct node **dstart)
{
   if (*dstart == NULL)
   {
      printf("Void deleation \n");
   }
   else
   {
      struct node *p;
      struct node *q;
      p = *dstart;
      while (p->next != NULL)
      {
         p = p->next;
      }
      int x = p->info;
      if (p->prev != NULL)
      {
         q = p->prev;
         free(p);
         q->next = NULL;
      }
      else
      {
         free(p);
         *dstart = NULL;
      }
      return x;
   }
}
int deleteBefore(struct node **dstart, struct node *p)
{
   if (p == NULL || p->prev == NULL)
   {
      printf("Void deletion \n");
      return -1;
   }
   else
   {
      struct node *q;
      q = p->prev;
      int x = q->info;
      if (q == *dstart)
      {
         p->prev = NULL;
         *dstart = p;
      }
      else
      {
         struct node *r;
         r = q->prev;
         r->next = p;
         p->prev = r;
      }
      free(q);
      return x;
   }
}
int deleteAfter(struct node **dstart, struct node *p)
{
   if (p == NULL || p->next == NULL)
   {
      printf("Void deletion \n");
      return -1;
   }
   else
   {
      struct node *q;
      q = p->next;
      int x = q->info;
      if (q->next == NULL)
      {
         p->next = NULL;
      }
      else
      {
         struct node *r;
         r = q->next;
         p->next = r;
         r->prev = p;
      }
      free(q);
      return x;
   }
}
void traverse(struct node *dstart)
{
   struct node *p;
   p = dstart;
   while (p != NULL)
   {
      printf("%d ", p->info);
      p = p->next;
   }
   printf("\n");
}
int main()
{
   struct node *dstart;
   dstart = NULL;
   insertend(&dstart, 10);
   insertend(&dstart, 20);
   insertend(&dstart, 30);
   insertend(&dstart, 40);
   insertend(&dstart, 50);
   printf("Linked list \n");
   traverse(dstart);
   struct node *p;
   p = dstart;
   int d;
   scanf("%d", &d); // position after which we want to delete or (before insert) or before which we need to delete or (after insert)
   if (d == 0)
      p = NULL;
   for (int i = 1; i < d; i++)
   {
      p = p->next;
   }
   deleteAfter(&dstart, p);
   printf("Final linked list \n");
   traverse(dstart);
}
