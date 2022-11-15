#include<stdlib.h>
#include<stdio.h>
#define size 5
struct Queue{
    int item[size];
    int front,rear;
};
void Initialize(struct Queue *Q)
{
    Q->front=2;
    Q->rear=2;
}
int IsEmpty(struct Queue *Q)
{
    if(Q->rear==Q->front)
    {
        return 1;
    }
    return 0;
}
void Enqueue(struct Queue *Q,int x)
{
     if(((Q->rear + 1)%size)==Q->front)
     {
        printf("queue overflow\n");
        return;
     }
     Q->rear=(Q->rear+1)%size;
     Q->item[Q->rear]=x;
}
int dequeue(struct Queue *Q)
{
    if(IsEmpty(Q))//*(&Q)
    {
        printf("Queue underflow\n");
        return -1;
    }
    Q->front=(Q->front+1)%size;
    int x=Q->item[Q->front];
    return x;
}
int main()
{
   struct Queue Q;
   Initialize(&Q);
   Enqueue(&Q,2);
   Enqueue(&Q,3);
   Enqueue(&Q,4);
   Enqueue(&Q,5);
   int p=dequeue(&Q);
   int q=dequeue(&Q);
   int k=dequeue(&Q);
   int c=dequeue(&Q);
   int d=dequeue(&Q);
  printf("%d%d%d%d",p,q,k,c);

}
