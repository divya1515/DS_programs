#include<stdlib.h>
#include<stdio.h>
struct node{
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
void insertbeg(struct node **dstart,int x)
{
   struct node *p;
   struct node *q;
   p=*dstart;
   q=GetNode();
   q->info=x;
   q->prev=NULL;
   if(p!=NULL)
   {
   p->prev=q;
   q->next=p;
   }
   else
   q->next=NULL;
   *dstart=q;
}
void insertend(struct node **dstart,int x)
{
    struct node *p;
    p=*dstart;
    struct node *q;
    q=GetNode();
    q->info=x;
    q->next=NULL;
    if(p!=NULL)
    {
    while(p->next!=NULL)
    {
      p=p->next;
    }
    q->prev=p;
    p->next=q;
    }
    else
    {
     q->prev=NULL;
     *dstart=q;

    }
}
void insertAfter(struct node **dstart,struct node *p,int x)
{//p q r(insertion after p)
   if(p==NULL)
   {
      insertbeg(&(*dstart),x);
   }
   else
   {
   struct node *q;
   q=GetNode();
   q->info=x;
   struct node *r;
   if(p->next==NULL)
   {
      q->prev=p;
      p->next=q;
      q->next=NULL;
   }
   else
   {
   r=p->next;
   q->next=r;
   r->prev=q;
   q->prev=p;
   p->next=q;
   }
   }
}
void insertBefore(struct node **dstart,struct node *p,int x)
{//r q p
   if(p==NULL)
   {
      insertbeg(&(*dstart),x);
   }
   else
   {
   struct node *q;
   q=GetNode();
   q->info=x;
   if(p->prev==NULL)
   {
      q->prev=NULL;
      q->next=p;
      p->prev=q;
      *dstart=q;
   }
   else
   {
   struct node *r;
   r=p->prev;
   r->next=q;
   q->prev=r;
   q->next=p;
   p->prev=q;
   }
   }
}
void traverse(struct node *dstart)
{
   struct node *p;
   p=dstart;
   while(p!=NULL)
   {
      printf("%d ",p->info);
      p=p->next;
   }
   printf("\n");
}
int main()
{
   struct node *dstart;
   dstart=NULL;
   insertend(&dstart,10);
   insertend(&dstart,20);
   insertend(&dstart,30);
   insertend(&dstart,40);
   insertend(&dstart,50);

   struct node*p;
   p=dstart;
  int d;
  scanf("%d",&d);//position after which we want to insert or before which we are need to insert
  if(d==0)
    p=NULL;
  for(int i=1;i<d;i++)
  {
    p=p->next;
  }
  insertBefore(&dstart,p,5);  
   traverse(dstart);

}
