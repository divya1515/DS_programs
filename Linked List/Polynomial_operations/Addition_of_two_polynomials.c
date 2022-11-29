//Assumption: exponent of x(power of x)will be given in decreasing order like x^5+x^3+x^2..
#include <stdlib.h>
#include <stdio.h>
struct node
{
   int coff;
   int exp;
   struct node *next;
};
struct node *GetNode()
{
   struct node *p;
   p = (struct node *)malloc(sizeof(struct node));
   return p;
}
void InsertBeg(struct node **start, int n,int pow)
{
   struct node *p;
   p = GetNode();
   p->coff=n;
   p->exp=pow;
   p->next = *start;
   *start = p;
}
void Insertend(struct node **start, int n,int pow)
{
   if((*start)==NULL)
   {
     InsertBeg(&(*start),n,pow);
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
   p->coff = n;
   p->exp = pow;
   p->next=NULL;
   q->next = p;
   }
}
void traverse(struct node *start)
{
   struct node *p;
   p = start;
   while (p != NULL)
   {
      printf("%dx^%d + ",p->coff,p->exp);
      p = p->next;
   }
   printf("\n");
}
void InsertAfter(struct node *q, int n,int pow)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = GetNode();
   p->coff = n;
   p->exp  =pow;
   p->next = r;
   q->next = p;
}
struct node *Poly_Addition(struct node **start,struct node **start1)
{
   struct node *poly3;
   poly3=NULL;
   struct node *p;
   struct node *q;
   p=*start;
   q=*start1;
   while(p!=NULL && q!=NULL)
   {
      if(p->exp==q->exp)
      {
         Insertend(&poly3,p->coff+q->coff,p->exp);
          p=p->next;
          q=q->next;
      }
      else if(p->exp>q->exp)
      {
          Insertend(&poly3,p->coff,p->exp);
          p=p->next;
      }
      else
      {
         Insertend(&poly3,q->coff,q->exp);
          q=q->next;
      }
   }
   while(p!=NULL)
   {
       Insertend(&poly3,p->coff,p->exp);
          p=p->next;
   }
   while(q!=NULL)
   {
       Insertend(&poly3,q->coff,q->exp);
          q=q->next;
   }
   printf("Final polynomail after addition ");
   return poly3;
}
int main()
{
   struct node *start;
   start = NULL;

   Insertend(&start,2,5);
   Insertend(&start,3,4);
    Insertend(&start,3,3);
   Insertend(&start,3,2);
   printf("Polynomial1: ");
   traverse(start);
   struct node *start1;
   start1=NULL;
   Insertend(&start1,2,6);
   Insertend(&start1,3,5);
   Insertend(&start1,3,4);
   printf("Polynomial2: ");
   traverse(start1);
   struct node *start3;
   start3=Poly_Addition(&start,&start1);
   traverse(start3);
}
