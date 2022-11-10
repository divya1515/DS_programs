#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void traverse(int *ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<*ptr+i<<" ";
    }
}

int main(){

   int n;
   cin>>n;
   int nums[n];
   for(int i=0;i<n;i++)
   {
    cin>>nums[i];
   }
   traverse(nums,n);// nums[0] address as nums
}
