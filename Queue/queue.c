#include<stdlib.h>
#include<stdio.h>
#define MaxQueue 3
struct Queue{
    int item[MaxQueue];
    int front,rear;
};
void Initialize(struct Queue *Q)
{
  Q->front=0;
  Q->rear=-1;
}
void enqueue(struct Queue *Q,int x)
{
   if(Q->rear==MaxQueue-1)
   {
      printf("Queue Overflow\n");
      return;
   }
   Q->rear=Q->rear+1;
   Q->item[Q->rear]=x;
}
int IsEmpty(struct Queue *Q)
{
    if(Q->rear-Q->front+1==0)
    return 1;
    else
    return 0;
}
int dequeue(struct Queue *Q)
{
    if(IsEmpty(*(&Q)))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int x=Q->item[Q->front];
    Q->front=Q->front+1;
    return x;
}

int main()
{
    struct Queue Q;
    Initialize(&Q);
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,3);
    enqueue(&Q,4);
   int p=dequeue(&Q);
   int s=dequeue(&Q);
   printf("%d %d",p,s);

}
