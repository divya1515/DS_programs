#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,minidx;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        minidx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minidx])
            {
                minidx=j;
            }
        }
        swap(arr[i],arr[minidx]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}