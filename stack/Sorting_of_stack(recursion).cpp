#include<bits/stdc++.h>
using namespace std;
#define stacksize 10
void Insert_sorted_order(stack<int>&s,int num)
{
   if(s.empty()||s.top()<num)
   {
      s.push(num);
      return;
   }
   int x=s.top();
   s.pop();
   Insert_sorted_order(s,num);
   s.push(x);
}
void sorted_stack(stack<int>&s)
{
   if(s.empty())
   return;
   int num=s.top();
   s.pop();
   sorted_stack(s);
   Insert_sorted_order(s,num);
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
   sorted_stack(s);
    while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
}
