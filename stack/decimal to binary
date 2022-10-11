#include<stdlib.h>
#include<stdio.h>
#define stacksize 10
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
int IsEmpty()
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    return 0;
}
void decimaltoBinary(int n)
{
    int rem;
    Initialize();
    while(n!=0)
    {
        rem=n%2;
        push(rem);
        n/=2;    
    }
    while(!IsEmpty())
    {
       int x=pop();
        printf("%d",x);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    decimaltoBinary(n);
}
