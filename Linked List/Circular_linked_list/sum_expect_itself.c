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
struct node *pattern(struct node **cstart)
{
    struct node *p;
    p=(*cstart)->next;
    int sum=0;
    while(p!=*cstart)
    {
      sum=sum+p->info;
      p=p->next;
    }
    sum=sum+p->info;
    struct node *q;
    q=(*cstart)->next;
    while(q!=*cstart)
    {
        q->info=sum-(q->info);
        q=q->next;
    }
    q->info=sum-(q->info);
    return *cstart;
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
   InsertBeg(&start, 2);
   Insertend(&start, 3);
   Insertend(&start, 4);
   printf("Linked list\n");
   traverse(start);
   pattern(&start);
   printf("Final linked list\n");
   traverse(start);
}
