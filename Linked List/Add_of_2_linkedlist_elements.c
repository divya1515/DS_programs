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
void reverse(struct node **start)
{
   struct node *p;
   struct node *c;
   struct node *n;
   p = NULL;
   c = *start;
   n = c->next;
   while (c != NULL)
   {
      c->next = p;
      p = c;
      c = n;
      if (n != NULL)
      {
         n = n->next;
      }
   }
   *start = p;
}
struct node *add_of_two_linkedlist(struct node **start, struct node **start1)
{
   reverse(&(*start));
   reverse(&(*start1));
   struct node *start3;
   struct node *p;
   struct node *q;
   start3 = NULL;
   p = *start;
   q = *start1;
   int carry = 0;
   int sum, total;
   while (p != NULL && q != NULL)
   {
      total = p->info + q->info + carry;
      sum = total % 10;
      carry = total / 10;
      p = p->next;
      q = q->next;
      InsertBeg(&start3, sum);
   }
   while (p != NULL)
   {
      total = p->info + carry;
      sum = total % 10;
      carry = total / 10;
      InsertBeg(&start3, sum);
      p = p->next;
   }
   while (q != NULL)
   {
      total = q->info + carry;
      sum = total % 10;
      carry = total / 10;
      InsertBeg(&start3, sum);
      q = q->next;
   }
   if (carry > 0)
      InsertBeg(&start3, carry);
   return start3;
}
int main()
{
   struct node *start;
   struct node *start1;
   start = NULL;
   Insertend(&start, 9);
   Insertend(&start, 2);
   Insertend(&start, 5);
   printf("1st linked list ");
   traverse(start);
   start1 = NULL;
   Insertend(&start1, 9);
   Insertend(&start1, 9);
   printf("2nd linked list :");
   traverse(start1);
   struct node *ans;
   printf("linked list After addition:");
   ans = add_of_two_linkedlist(&start, &start1);
   traverse(ans);
}
