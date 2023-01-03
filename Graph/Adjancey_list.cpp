#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cout<<"How many vertices: ";
    cin>>v;
    cout<<"Edges: ";
    cin>>e;
    vector<int>AdjcntList[v];
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter the end point of edges"<<i<<":";
        int a,b;
        cin>>a>>b;
        AdjcntList[a].push_back(b);
        AdjcntList[b].push_back(a);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<":";
        for(int j=0;j<AdjcntList[i].size();j++)
        {
            cout<<AdjcntList[i][j]<<" ";
        }
        cout<<"\n";
    }

}
