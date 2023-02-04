//Transitie closure floyd warshall algorithim
#include <bits/stdc++.h>
using namespace std;
void Transitive_closure(vector<vector<int>>&AdjcntMatrix,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                AdjcntMatrix[i][j]=AdjcntMatrix[i][j]|(AdjcntMatrix[i][k]&AdjcntMatrix[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<AdjcntMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int v,e;
    cin>>v;
    cin>>e;
    vector<vector<int>>AdjcntMatrix(v,vector<int>(v,0));
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
       AdjcntMatrix[a][b]=1;
    }
    Transitive_closure(AdjcntMatrix,v);

}
