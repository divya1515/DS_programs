#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>AdjList[v];
    for(int i=1;i<=e;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        AdjList[a].push_back({b,w});
        AdjList[b].push_back({a,w});
    }
    priority_queue<pair<int,int>>pq;
    vector<int>pred(v,-1);
    vector<int>dis(v,INT_MAX);
    vector<int>InMst(v,0);
    dis[0]=0;
    pq.push({0,0});
    for(int i=1;i<v;i++)
    {
       pq.push({(-1)*dis[i],i});
    }
     for(int i=1;i<=v;i++)
    {
        int x=pq.top().second;
        pq.pop();
        InMst[x]=1;
        for(int j=0;j<AdjList[x].size();j++)
        {
            int vertex=AdjList[x][j].first;
            int weight=AdjList[x][j].second;
            if(InMst[vertex]==0 && dis[vertex]>dis[x]+weight)
            {
                pred[vertex]=x;
                dis[vertex]=weight+dis[x];
                pq.push({(-1)*dis[vertex],vertex});
            }
        }
        
    }
    for(int p=0;p<v;p++)
    {
        //vertex" "cost" "predeccessor
        cout<<p<<" "<<dis[p]<<" "<<pred[p]<<"\n";
    }
}
