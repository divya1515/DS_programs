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
void insertAfter(struct node *q, int x)
{
   struct node *p;
   p = GetNode();
   p->info = x;
   p->next = q->next;
   q->next = p;
}
int deleteAfter(struct node *p, struct node **cstart)
{
   struct node *q;
   q = p->next;
   int x = q->info;
   if (q == *cstart)
      *cstart = p;
   p->next = q->next;
   free(q);
   return x;
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
int largest_element(struct node **cstart)
{
   struct node *p;
   p = (*cstart)->next;
   int mx = -1;
   while (p != *cstart)
   {
      if (p->info > mx)
      {
         mx = p->info;
      }
      p = p->next;
   }
   if (p->info > mx)
   {
      mx = p->info;
   }
   return mx;
}
void delete_fibonicci_elements(struct node **cstart, int *dat)
{
   struct node *p;
   struct node *q;
   p = (*cstart)->next;
   q = *cstart;
   while (p != *cstart)
   {
      if (dat[p->info] == 1)
      {
         p = p->next;
         deleteAfter(q, &(*cstart));
      }
      else
      {
         q = p;
         p = p->next;
      }
   }
   if (dat[p->info] == 1)
   {
      deleteAfter(q, &(*cstart));
   }
}
int main()
{
   struct node *start;
   start = NULL;
   InsertBeg(&start, 1);
   Insertend(&start, 0);
   Insertend(&start, 2);
   Insertend(&start, 8);
   Insertend(&start, 3);
   Insertend(&start, 4);
   Insertend(&start, 6);
   printf("Linked list\n");
   traverse(start);
   int n;
   n = largest_element(&start);
   int dat[n];
   for (int i = 0; i < n; i++)
   {
      dat[i] = 0;
   }
   int a = 0;
   int b = 1;
   dat[a] = 1;
   dat[b] = 1;
   int c;
   for (int i = 2; i <= n; i++)
   {
      c = a + b;
      dat[c] = 1;
      a = b;
      b = c;
   }
   delete_fibonicci_elements(&start, dat);
   printf("Final list after deleating all fibonicci elements\n");
   traverse(start);
}
