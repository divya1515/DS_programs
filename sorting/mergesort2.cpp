#include <bits/stdc++.h>
using namespace std;
void mergearray(int a[],int low,int mid,int high)
{
    int c[high-low];
    int i=low,j=mid+1,k=low;
    while(j<=high && i<=mid)
    {
        if(a[i]>a[j])
        c[k++]=a[j++];
        else
        if(a[i]<a[j])
        c[k++]=a[i++];
        else
        {
        c[k++]=a[i++];
        j++;
        }
        }
        while(i<=mid)
        {
            c[k++]=a[i++];
        }
        while(j<=high)
        {
            c[k++]=a[j++];
        }
        for(int p=low;p<=high;p++)
        {
            a[p]=c[p];
        }
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    mergearray(a,low,mid,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int low=0,high=n-1;
    mergesort(a,low,high);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}