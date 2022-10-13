#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define stacksize 20
#define true 1
#define false 0
struct stack{
    char item[stacksize];
    int top;
};
struct stack s;
void Initialize()
{
   s.top=-1;
}
void push(char x)
{
     if(s.top==(stacksize-1))
     {
        printf("Stack overflows");
        return;
     }
    s.top=s.top+1;
     s.item[s.top]=x;
}
char pop()
{
    char x;
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
void validParanthesis(char str[13])
{
   int flag=0;
   int i=0;
   while(str[i]!='\0')
   {
      if(str[i]=='(')
      {
        push(str[i]);
      }
      else
      {
        if(IsEmpty())
        {
          flag=1;
          break;
        }
        pop();
      }
     i++;
   }
  
   if(flag==0)
   {
      if(!IsEmpty())
      {
        printf("INVALID\n");
      }
      else
      printf("Valid\n");
   }
   else
   printf("Invalid");
}
int main()
{
  char str[13];
  gets(str);
  Initialize();
  validParanthesis(str);
  
}
