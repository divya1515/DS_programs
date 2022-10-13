#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define stacksize 20
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
void swap(char *a,char *b)
{
  char t;
  t=*a;
  *a=*b;
  *b=t;
}
void reverse(char str[20])
{
  int i=0,c=0;
    while(str[i]!='\0')
    {
      c++;
      i++;
    }
    for(int j=0;j<c/2;j++)
    {
      swap(&str[j],&str[c-1-j]);
    }
}
int evaluate(int a,int b,char op)
{
    switch(op)
    {
        case '+':return a+b;
        break;
        case '-':return a-b;
        break;
        case '*':return a*b;
        break;
        case '/':return a/b;
        break;
        case '^':return pow(b,a);
        break;
    }
}
int i=0;
void prefix(char str[20])
{
   while(str[i]!='\0')
   { 
    while(str[i]>='0'&& str[i]<='9')
    {
        push(str[i]-'0');
        i++;
    }
     int a=pop();
     int b=pop();
     int value=evaluate(a,b,str[i]);
      push(value);
      i++;
   }
   int x=pop();
    printf("%d",x);
}

int main()
{
    char str[20];
   gets(str);
   reverse(str);
   Initialize();
   prefix(str);
}
