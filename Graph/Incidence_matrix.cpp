#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v;//vertices
    cin>>e;//edges
    vector<vector<int>>IncidenceMatrix(v,vector<int>(e,0));
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        IncidenceMatrix[a][i-1]=1;
        IncidenceMatrix[b][i-1]=1;
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<":";
        for(int j=0;j<e;j++)
        {
            cout<<IncidenceMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}
