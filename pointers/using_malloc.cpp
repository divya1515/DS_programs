#include <bits/stdc++.h>
using namespace std;
void iou(int *ptr,int n)
{
     for(int i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));
    }
     for(int i=0;i<n;i++)
    {
        printf("%d",*(ptr+i));
    }
}
int main()
{ 
    int n;
    cin>>n;
    int *ptr;
   
    ptr=(int*)malloc(n*sizeof(int));
    iou(ptr,n);

}
