#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cout<<"How many vertices: ";
    cin>>v;
    cout<<"Edges: ";
    cin>>e;
    vector<vector<int>>AdjcntMatrix(v,vector<int>(v,0));
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter the end point of edges"<<i<<":";
        int a,b;
        cin>>a>>b;
       AdjcntMatrix[a][b]=1;
       AdjcntMatrix[b][a]=1;

    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<":";
        for(int j=0;j<v;j++)
        {
            cout<<AdjcntMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}
