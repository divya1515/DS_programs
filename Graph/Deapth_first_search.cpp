#include <bits/stdc++.h>
using namespace std;
void DFS_visit(int i,vector<int>&visited,vector<int>AdjList[],vector<int>&pred)
{
    cout<<i<<" "<<pred[i];// dfs with its predeccessor
    cout<<"\n";
    visited[i]=1;
    for(int j=0;j<AdjList[i].size();j++)
    {
        if(visited[AdjList[i][j]]==0)
        {
            pred[AdjList[i][j]]=i;
            DFS_visit(AdjList[i][j],visited,AdjList,pred);
        }
    }
}
void DFS(vector<int>AdjList[],int v)
{
   vector<int>visited(v);
   vector<int>dis(v);
   vector<int>pred(v,-1);
   for(int i=0;i<v;i++)
   {
      if(visited[i]==0)
      {
        DFS_visit(i,visited,AdjList,pred);
      }
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
    }
    DFS(AdjcntList,v);
}
