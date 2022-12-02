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
struct node *concatenate(struct node **cstart1,struct node **cstart2)
{
   struct node *p;
   p=(*cstart1)->next;
   (*cstart1)->next=(*cstart2)->next;
   (*cstart2)->next=p;
   return *cstart2;
   
}
int main()
{
   struct node *start;
   start = NULL;
   Insertend(&start, 200);
   Insertend(&start, 300);
   Insertend(&start, 400);
   Insertend(&start, 500);
   Insertend(&start, 600);
   Insertend(&start, 10);
   Insertend(&start, 20);
   Insertend(&start, 30);
   printf("1st Linked list\n");
   traverse(start);
   struct node *start1;
   start1 = NULL;
   Insertend(&start1, 2);
   Insertend(&start1, 3);
   Insertend(&start1, 4);
   Insertend(&start1, 5);
    printf("2nd Linked list\n");
   traverse(start1);
   struct node *ans;
   ans=concatenate(&start,&start1);
   printf("Concated linked list\n");
   traverse(ans);
}
