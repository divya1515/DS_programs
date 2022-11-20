#include<bits/stdc++.h>
#include<queue>
using namespace std;
void reversal(queue<int>&q)
{
   if(q.empty())
   return;
   int num=q.front();
   q.pop();
   reversal(q);
   q.push(num);
}
int main()
{
   queue<int>q;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      q.push(x);
   }
   reversal(q);
   while(!q.empty())
   {
      cout<<q.front();
      q.pop();
   }
}
