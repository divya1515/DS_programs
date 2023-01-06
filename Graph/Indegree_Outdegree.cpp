#include <bits/stdc++.h>
using namespace std;
void Indegree_Outdegree(vector<int>AdjList[],int v)
{
   vector<int>indeg(v);
    vector<int>outdeg(v);
   for(int i=0;i<v;i++)
   {
      outdeg.push_back(AdjList[i].size());
      for(int j=0;j<AdjList[i].size();j++)
      {
         indeg[AdjList[i][j]]++;
      }

   }
   cout<<"Indegree: ";
   cout<<"\n";
   for(int i=0;i<v;i++)
   {
       cout<<indeg[i];
   }
}
int main()
{
    int v,e;
   
    cin>>v;
    
    cin>>e;
    vector<int>AdjcntList[v];
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        AdjcntList[a].push_back(b);
    }
   Indegree_Outdegree(AdjcntList,v);
}
