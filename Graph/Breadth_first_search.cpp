#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int>AdjList[],int v)
{
   vector<int>visited(v);
   queue<int>q;
   q.push(0);
   visited[0]=1;
   while(!q.empty())
   {
      int x=q.front();
      q.pop();
      for(int i=0;i<AdjList[x].size();i++)
      {
         if(visited[AdjList[x][i]]==0)
         {
            q.push(AdjList[x][i]);
            visited[AdjList[x][i]]=1;
         }
      }
      cout<<x<<" ";
   }
}
int main()
{
    int v,e;
    cin>>v;//vertices
    cin>>e;//edges
    vector<int>AdjcntList[v];
    for(int i=1;i<=e;i++)
    {
        int a,b;// end point of edges a and b
        cin>>a>>b;
        AdjcntList[a].push_back(b);
        AdjcntList[b].push_back(a);
    }
    BFS(AdjcntList,v);
}
