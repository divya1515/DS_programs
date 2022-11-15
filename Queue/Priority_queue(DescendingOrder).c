#include<stdlib.h>
#include<stdio.h>
#define N 3
struct PriorityQueue{
    int arr[N];
    
};
void Array_Insertion(struct PriorityQueue *pq,int *n,int i,int x)
{
    for(int j=*n;j>i;j--)
    {
        pq->arr[j]=pq->arr[j-1];
    }
    pq->arr[i]=x;
    // for(int k=0;k<=*n;k++)
    // {
    //     printf("%d  ",pq->arr[k]);
    // }
    // printf("\n");
    *n=*n+1;

}
void Insert(struct PriorityQueue *pq,int *n,int x)
{
    int i=*n-1;
    if(i==N)
    {
        printf("Priorityqueue overflow\n");
    }
    while(i>=0 && pq->arr[i]<=x)
    {
        i--;
    }
    Array_Insertion(pq,n,(i+1),x);
}
int deletion(struct PriorityQueue *pq,int *n)
{
    if(*n==0)
    {
        printf("underflow\n");
    }
    int x=pq->arr[*n-1];
    *n=*n-1;
    return x;
}
int main()
{
    struct PriorityQueue pq;
    int n=0;
    Insert(&pq,&n,3);
    Insert(&pq,&n,4);
    Insert(&pq,&n,1);
    Insert(&pq,&n,2);
    Insert(&pq,&n,6);
    int k=deletion(&pq,&n);
    int t=deletion(&pq,&n);
    int s=deletion(&pq,&n);
    int d=deletion(&pq,&n);
     int i=deletion(&pq,&n);
      printf("\n%d %d %d %d %d ",k,t,s,d,i);
      int o=deletion(&pq,&n);
}
