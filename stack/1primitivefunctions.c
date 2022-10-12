#include<stdlib.h>
#define stacksize 3
#define true 1
#define false 0
struct stack{
    int item[stacksize];
    int top;
};
struct stack s;
void Initialize()
{
   s.top=-1;
}
void IsEmpty()
{
    if(s.top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    return;
}
void push(int x)
{
     if(s.top==(stacksize-1))
     {
        printf("Stack overflows");
        return;
     }
    s.top=s.top+1;
     s.item[s.top]=x;
}
int pop()
{
    int x;
    if(s.top==-1)
    {
        printf("Stack underflows");
        return 0;
    }
    x=s.item[s.top];
    s.top=s.top-1;
    return x;
}
int main()
{
    int x;
    Initialize();
    push(400);
    push(600);
    push(987);
    push(567);
   x=pop();
   printf("POPED element: %d\n",x);
    x=pop();
     printf("POPED element: %d",x);
     IsEmpty();


}

