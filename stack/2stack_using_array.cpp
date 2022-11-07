#include<bits/stdc++.h>
using namespace std;
#define size 8
int arr[size];
int top2=size;
int top1=-1;

void push1(int x)
{
   top1++;
   if(top2-top1==0)
   {
    cout<<"Stack overflow";
   }
   else
   arr[top1]=x;

}
void push2(int x)
{
   top2--;
   if(top2-top1==0)
   {
    cout<<"stack overflow";
   }
   else
   arr[top2]=x;
}
int pop1()
{
   if(top1==-1)
   cout<<"stack underflow";
   else
   {
     int y=arr[top1];
     top1--;
     return y;
   }
   return 0;
}
int pop2()
{
    if(top2==size)
    cout<<"stack underflow";
    else
    {
       int y=arr[top2];
       top2++;
       return y;
    }
    return 0;
}
int main()
{
    push1(32);
    push2(45);
    push1(23);
    push2(34);
    cout<<pop2()<<"\n";
    cout<<pop2()<<"\n";
    push2(67);
    push1(98);
    push1(56);
    cout<<pop2()<<" ";
    cout<<pop1()<<" ";
    cout<<pop1()<<" ";
}
