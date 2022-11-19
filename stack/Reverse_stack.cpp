#include<bits/stdc++.h>
using namespace std;
#define stacksize 10
void Insert_bottom(stack<int>&s,int x)
{
   if(s.empty())
   {
       s.push(x);
       return;
   }
   int num=s.top();
   s.pop();
   Insert_bottom(s,x);
   s.push(num);
}
void reverse_stack(stack<int>&s)
{
   if(s.empty())
   return ;
   int num=s.top();
   s.pop();
   reverse_stack(s);
   Insert_bottom(s,num);
}
int main()
{
   stack<int>s;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      s.push(x);
   }
   reverse_stack(s);
    while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
}
