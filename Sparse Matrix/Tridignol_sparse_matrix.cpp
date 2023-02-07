#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
            if(v[i][j]!=0)
            c++;
        }
    }
    vector<int>ans(c);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]!=0)
            {
                int t=(2*(i+1))+(j+1)-2;
                ans[t-1]=v[i][j];
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        cout<<ans[i]<<" ";
    }
}
