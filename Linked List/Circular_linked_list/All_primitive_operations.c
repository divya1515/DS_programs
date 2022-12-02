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
void InsertBeg(struct node **cstart, int x)
{
   struct node *p;
   p = GetNode();
   p->info = x;
   if ((*cstart) != NULL)
   {
      p = (*cstart)->next;
      (*cstart)->next = p;
   }
   else
   {
      *cstart = p;
      (*cstart)->next = p;
   }
}
void Insertend(struct node **cstart, int x)
{
   struct node *p;
   p = GetNode();
   p->info = x;
   if (*cstart == NULL)
   {
      *cstart = p;
      p->next = *cstart;
   }
   else
   {
      p->next = (*cstart)->next;
      (*cstart)->next = p;
      *cstart = p;
   }
}
void insertAfter(struct node *q, int x)
{
   struct node *p;
   p = GetNode();
   p->info = x;
   p->next = q->next;
   q->next = p;
}
int deleteAfter(struct node *p, struct node **cstart)
{
   struct node *q;
   q = p->next;
   int x = q->info;
   if (q == *cstart)
      *cstart = p;
   p->next = q->next;
   free(q);
   return x;
}
int deletebeg(struct node **cstart)
{
   if (*cstart == NULL)
   {
      printf("Void deleation\n");
   }
   else
   {
      struct node *p;
      p = (*cstart)->next;
      if ((*cstart)->next == (*cstart))
      {
         *cstart = NULL;
      }
      else
         (*cstart)->next = p->next;
      int x = p->info;
      free(p);
      return x;
   }
}
int deletelast(struct node **cstart)
{
   if (*cstart == NULL)
   {
      printf("Void deleation \n");
   }
   else
   {
      struct node *q;
      struct node *p;
      q = *cstart;
      p = (*cstart)->next;
      while (p->next != *cstart)
      {
         p = p->next;
      }
      int x = q->info;
      if (p->next != q->next)
      {
         p->next = q->next;
         *cstart = p;
      }
      else
      {
         *cstart = NULL;
      }
      free(q);
      return x;
   }
}
void traverse(struct node *cstart)
{
   struct node *p;
   p = cstart;
   p = p->next;
   while (p != cstart)
   {
      printf("%d ", p->info);
      p = p->next;
   }
   printf("%d ", p->info);
   printf("\n");
}
int main()
{
   struct node *start;
   start = NULL;
   int d;
   scanf("%d", &d); // position after which we need to insert or position after which we need to delete
   InsertBeg(&start, 200);
   Insertend(&start, 300);
   Insertend(&start, 400);
   printf("Linked list\n");
   traverse(start);
   struct node *p;
   p = start->next;
   for (int i = 1; i < d; i++)
   {
      p = p->next;
   }
   insertAfter(p, 7);//inserting 7 after address p
   deleteAfter(p,&start);//deleating after address p
   printf("Linked list final\n");
   traverse(start);
}
