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
int DeleteEnd(struct node **start)
{
   struct node *q;
   struct node *p;
   q=NULL;
   p=*start;
   while(p->next!=NULL)
   {
      q=p;
      p=p->next;
   }
   int x=p->info;
   free(p);
   q->next=NULL;
   return x;
}
int deleteAfter(struct node *p)
{
   struct node *q;
   struct node *r;
   if(p==NULL || p->next ==NULL)
   {
     printf("Void deleation\n");
     return -1;
   }
   q=p->next;
   int x=q->info;
   r=q->next;
   p->next=r;
   free(q);
   return x;
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
   int d;
   int flag=1;
   scanf("%d",&d);//position to be deleated
   struct node *p=start;
   if(d==1)
   {
    int k= DeleteBeg(&start);
    if(k==-1)
    flag=0;
     
   }
   else
   {
   for(int i=1;i<d-1;i++)
   {
     p=p->next;
   }
   int k=deleteAfter(p);
   if(k==-1)
   {
      flag=0;
   }
   }
   if(flag==1)
   {
   printf("after deleation\n");
   traverse(start);
   }
}
