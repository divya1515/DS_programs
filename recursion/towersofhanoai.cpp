#include<bits/stdc++.h>
using namespace std;
void towersofhanoai(int n,char s,char m,char d)
{
     if(n==1)
     {
        cout<<s<<"-"<<d<<endl;
     }
     else
     {
        towersofhanoai(n-1,s,d,m);
        cout<<s<<"-"<<d<<endl;
        towersofhanoai(n-1,m,s,d);
     }
}
int main()
{
    int n;
    cin>>n;
    char s,m,d;
    towersofhanoai(n,'s','m','d');
}//(2^n)-1 steps where n are the no. of disk
