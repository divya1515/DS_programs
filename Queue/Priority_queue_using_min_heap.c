#include<stdlib.h>
#include<stdio.h>
#define size 10
struct PriorityQueue{
    int arr[size];
};
void swap(int *x,int *y)
{
   int t=*x;
   *x=*y;
   *y=t;
}
void Insert(struct PriorityQueue *pq,int *n,int key)
{
   pq->arr[*n]=key;
   int i=*n;
   int j=(i-1)/2;
   while(i>0 && pq->arr[j]>pq->arr[i])
   {
      swap(&pq->arr[i],&pq->arr[j]);
      i=j;
      j=(i-1)/2;
   }
   *n=*n+1;
}
void MinHeapify(struct PriorityQueue *pq,int *n)
{
   int i=0;
   while(((2*i)+1)<=(*n)-1)
   {
      int left=2*i+1;
      int right=2*i+2;
      int mn=left;
      if(right<=*n-1)
      {
        if(pq->arr[left]>pq->arr[right])
        mn=right;
      }
      if(pq->arr[mn]<pq->arr[i])
      swap(&pq->arr[mn],&pq->arr[i]);
      i=mn;
   }
}
int delete(struct PriorityQueue *pq,int *n)
{
   int x=pq->arr[0];
   pq->arr[0]=pq->arr[(*n)-1];
   *n=*n-1;
   MinHeapify(&(*pq),&(*n));
   return x;
}
int main()
{
    struct PriorityQueue pq;
    int n=0;
    Insert(&pq,&n,45);
    Insert(&pq,&n,32);
    Insert(&pq,&n,54);
    Insert(&pq,&n,1);
    Insert(&pq,&n,32);
    Insert(&pq,&n,46);
    int k=delete(&pq,&n);
    int w=delete(&pq,&n);
    int s=delete(&pq,&n);
    int f=delete(&pq,&n);
    printf("%d %d %d %d",k,w,s,f);

}
