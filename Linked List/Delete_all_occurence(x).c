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
void DeleteBeg(struct node **start)
{
   struct node *p;
   if ((*start) == NULL)
   {
      printf("Void deleation\n");
   }
   else
   {
      p = *start;
      *start = p->next;
      free(p);
   }
}
void deleteAfter(struct node **p)
{
   struct node *q;
   struct node *r;
   if (*p == NULL || (*p)->next == NULL)
   {
      printf("Void deleation\n");
   }
   else
   {
      q = (*p)->next;
      r = q->next;
      (*p)->next = r;
      free(q);
   }
}
void delete_all_occurence(struct node **start, int x)
{
   struct node *p;
   struct node *q;
   p = *start;
   q = NULL;
   while (p != NULL)
   {
      if (p->info == x)
      {
         if (q == NULL)
         {
            p = p->next;
            DeleteBeg(&(*start));
         }
         else
         {
            p = p->next;
            deleteAfter(&q);
         }
      }
      else
      {
         q = p;
         p = p->next;
      }
   }
}
int main()
{
   struct node *start;
   start = NULL;
   Insertend(&start, 2);
   Insertend(&start, 3);
   Insertend(&start, 3);
   Insertend(&start, 4);
   Insertend(&start, 6);
   Insertend(&start, 1);
   Insertend(&start, 3);
   Insertend(&start, 3);
   printf("Linked list\n");
   traverse(start);
   delete_all_occurence(&start, 3);//deleation of all 3 present in linked list
   printf("Final Linked list\n");
   traverse(start);
}
