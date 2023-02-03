#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>AdjList[v+1];
    for(int i=1;i<=e;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        AdjList[a].push_back({b,w});
        AdjList[b].push_back({a,w});
    }
    for(int i=1;i<=v;i++)
    {
        cout<<i<<":";
        for(int j=0;j<AdjList[i].size();j++)
        {
            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<"  ";
        }
        cout<<endl;
    }

}
