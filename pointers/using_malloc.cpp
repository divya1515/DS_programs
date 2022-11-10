#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    int *p;
    p=(int*)malloc(40);
    for(int i=0;i<7;i++)
    {
        scanf("%d",(p+i));
    }
    for(int i=0;i<7;i++)
    {
        printf("%d",*(p+i));
    }
    char *ptr;
    ptr=(char*)malloc(10);
    for(int i=0;i<10;i++)
    {
        scanf("%c",(ptr+i));
    }
    for(int i=0;i<10;i++)
    {
        printf("%c",*(ptr+i));
    }

}
