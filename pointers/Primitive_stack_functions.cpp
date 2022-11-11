#include<stdlib.h>
#include<stdio.h>
#define stacksize 30
#define true 1
#define false 0
struct stack{
    int item[stacksize];
    int top;
};
void Initialize(struct stack *s)
{
   s->top=-1;
}
int IsEmpty(struct stack s)
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    return 0;
}
void push(struct stack *s,int x)
{
     if(s->top==(stacksize-1))
     {
        printf("Stack overflows");
        return;
     }
    s->top=s->top+1;
     s->item[s->top]=x;
}
int pop(struct stack *s)
{
    int x;
    if(s->top==-1)
    {
        printf("Stack underflows");
        return 0;
    }
    x=s->item[s->top];
    s->top=s->top-1;
    return x;
}
int top(struct stack s)
{
    int x;
    x=s.item[s.top];
    return x;
}
int main()
{
    int x;
    struct stack S;
    Initialize(&S);
    push(&S,400);
    push(&S,600);
    push(&S,987);
    push(&S,567);
   x=pop(&S);
    printf("POPED element: %d\n",x);
    x=pop(&S);
    int y=top(S);
    printf("TOP: %d\n",y);
     printf("POPED element: %d\n",x);
    printf("%d",IsEmpty(S));

}
