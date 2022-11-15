#include<stdlib.h>
#include<stdio.h>
#define N 10
struct PriorityQueue{
    int arr[N];
    
};
void Array_Insertion(struct PriorityQueue *pq,int *n,int i,int x)
{
    for(int j=*n;j>=i;j--)
    {
        pq->arr[j+1]=pq->arr[j];
    }
    pq->arr[i]=x;
    *n=*n+1;
}
void Insert(struct PriorityQueue *pq,int *n,int x)
{
    if(*n==N-1)
    {
        printf("Queue overflow\n");
        return;
    }
    int i=0;
     while(i<*n && pq->arr[i]<=x)
     {
        i++;
     }
    Array_Insertion(pq,n,i,x);
}
int deletion(struct PriorityQueue *pq,int *n)
{
    if(*n==0)
    {
        printf("Queue Underflow\n");
        return -1;
    }
   int x=pq->arr[0];
   for(int j=1;j<=*n;j++)
   {
      pq->arr[j-1]=pq->arr[j];
   }
   *n=*n-1;
   return x;
}
int main()
{
    struct PriorityQueue pq;
    int n=0;
    Insert(&pq,&n,8);
    Insert(&pq,&n,1);
    Insert(&pq,&n,7);
    Insert(&pq,&n,2);
     printf("%d\n",deletion(&pq,&n));
     printf("%d\n",deletion(&pq,&n));
     printf("%d\n",deletion(&pq,&n));
     printf("%d\n",deletion(&pq,&n));
    deletion(&pq,&n);

}
