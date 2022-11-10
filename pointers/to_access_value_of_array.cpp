#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

   int a[4];
   int *ptr=a;//address of a[0]
   for(int i=0;i<4;i++)
   {
    cin>>a[i];
   }
   for(int i=0;i<4;i++)
   {
       cout<<*ptr+i;
   }
   cout<<"\n";
   for(int i=0;i<4;i++)
   {
       cout<<*a+i;
   }
}
