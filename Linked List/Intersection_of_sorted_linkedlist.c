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
   if(q==NULL)
   {
      InsertBeg(&(*start),x);
   }
   else
   {
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
void Intersection(struct node **start1, struct node **start2,struct node **start3)
{
   struct node *p;
   struct node *q;
   p=*start1;
   q=*start2;
   while(p!=NULL && q!=NULL)
   {
      if(p->info<q->info)
      {
        p=p->next;
      }
      else
      if(p->info==q->info)
      {
         Insertend(&(*start3),p->info);
         p=p->next;
         q=q->next;
      }
      else
      {
        q=q->next;
      }
   }
}
int main()
{
   struct node *start;
   struct node *start1;
   start = NULL;
   Ordered_Insertion(&start, 1);
   Ordered_Insertion(&start, 4);
   Ordered_Insertion(&start, 5);
   Ordered_Insertion(&start, 9);
   Ordered_Insertion(&start, 15);
   printf("1st linked list ");
   traverse(start);
   start1 = NULL;
   Ordered_Insertion(&start1, 2);
   Ordered_Insertion(&start1, 4);
   Ordered_Insertion(&start1, 15);
   Ordered_Insertion(&start1, 34);
   printf("2nd linked list :");
   traverse(start1);
   struct node *start3;
   start3=NULL;
   Intersection(&start, &start1,&start3);
   printf("Intersection linked list: ");
   traverse(start3);
}
