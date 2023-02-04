#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>Matrix_multiply(int v,vector<vector<int>>&mat1,vector<vector<int>>&mat2)
{
    vector<vector<int>>res(v,vector<int>(v,0));
    int i, j, k;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            res[i][j] = 0;
            for (k = 0; k < v; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return res;
}
void add(int v,vector<vector<int>>&A,vector<vector<int>>&B,vector<vector<int>>&C) 
{ 
    int i, j; 
    for (i = 0; i < v; i++) 
        for (j = 0; j < v; j++) 
            C[i][j] = A[i][j] + B[i][j]; 
} 
void Transitive_closure(vector<vector<int>>&AdjcntMatrix,int n)
{
    vector<vector<int>>M(n,vector<int>(n,0));
    M=AdjcntMatrix;
    vector<vector<int>>temp(n,vector<int>(n,0));
    temp=AdjcntMatrix;
    for(int i=1;i<n;i++)
    {
        temp=Matrix_multiply(n,temp,AdjcntMatrix);
        add(n,temp,M,M);
    }
    vector<vector<int>>T(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j]>0)
            T[i][j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<T[i][j]<<" ";
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
