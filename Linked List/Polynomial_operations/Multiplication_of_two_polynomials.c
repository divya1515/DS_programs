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
void InsertBeg(struct node **start, int n, int pow)
{
   struct node *p;
   p = GetNode();
   p->coff = n;
   p->exp = pow;
   p->next = *start;
   *start = p;
}
void Insertend(struct node **start, int n, int pow)
{
   if ((*start) == NULL)
   {
      InsertBeg(&(*start), n, pow);
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
      printf("(%dx^%d) + ", p->coff, p->exp);
      p = p->next;
   }
   printf("\n");
}
void InsertAfter(struct node **q, int n, int pow)
{
   struct node *r;
   struct node *p;
   r = (*q)->next;
   p = GetNode();
   p->coff = n;
   p->exp = pow;
   p->next = r;
   (*q)->next = p;
}
void Ordered_Insertion(struct node **poly3, int n, int pow)
{
   struct node *p;
   struct node *q;
   p = *poly3;
   q = NULL;
   while (p != NULL && p->exp > pow)
   {
      q = p;
      p = p->next;
   }
   if (q == NULL)
   {
      InsertBeg(&(*poly3), n, pow);
   }
   else
      InsertAfter(&q, n, pow);
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
struct node *Poly_Multiply(struct node **start, struct node **start1)
{
   struct node *poly3;
   poly3 = NULL;
   struct node *p;
   struct node *q;
   p = *start;
   q = *start1;
   while (q != NULL)
   {
      p = *start;
      while (p != NULL)
      {
         Ordered_Insertion(&poly3, (p->coff) * (q->coff), (p->exp) + (q->exp));
         p = p->next;
      }
      q = q->next;
   }
   p = poly3;
   while (p->next != NULL)
   {
      if ((p->exp) == (p->next->exp))
      {
         p->coff = p->coff + p->next->coff;
         deleteAfter(&p);
      }
      else
         p = p->next;
   }
   return poly3;
}
int main()
{
   struct node *start;
   start = NULL;

   Insertend(&start, 3, 2);
   Insertend(&start, 4, 3);
   Insertend(&start, 2, 2);
   printf("Polynomial1: ");
   traverse(start);
   struct node *start1;
   start1 = NULL;
   Insertend(&start1, 4, 3);
   Insertend(&start1, 4, 2);
   printf("Polynomial2: ");
   traverse(start1);
   struct node *start3;
   printf("Final polynomial: ");
   start3 = Poly_Multiply(&start, &start1);
   traverse(start3);
}
