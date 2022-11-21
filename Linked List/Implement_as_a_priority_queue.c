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
void Ordered_Insertion(struct node **start, int x)
{
   struct node *p;
   struct node *q;
   p = *start;
   q = NULL;
   while (p != NULL && p->info <= x)
   {
      q = p;
      p = p->next;
   }
   if (q == NULL)
   {
      InsertBeg(&*start, x);
   }
   else
      InsertAfter(q, x);
}
int DeleteBeg(struct node **start)
{
   struct node *p;
   if((*start) == NULL)
   {
      printf("Void deleation\n");
      return -1;
   }
   else
   {
   p=*start;
   int x=p->info;
   *start=p->next;
   free(p);
   return x;
   }
}
int main()
{
   struct node *start;
   start = NULL;
   Ordered_Insertion(&start, 200);
   Ordered_Insertion(&start, 300);
   Ordered_Insertion(&start, 400);
   Ordered_Insertion(&start, 500);
   Ordered_Insertion(&start, 600);
   Ordered_Insertion(&start, 10);
   Ordered_Insertion(&start, 20);
   Ordered_Insertion(&start, 30);
   printf("Linked list before deleation\n");
   traverse(start);
   printf("\n%d",DeleteBeg(&start));
   printf("\n%d",DeleteBeg(&start));
   printf("\n%d",DeleteBeg(&start));
   printf("\n");
   Ordered_Insertion(&start,45);
   printf("Linked list after deleation like priority Queue\n");
   traverse(start);

}
