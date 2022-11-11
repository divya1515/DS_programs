#include <bits/stdc++.h>
using namespace std;
struct student
{
    int roll;
    char name[15];
    double perc;
};
void input(struct student *ptr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d%s%lf", &((ptr + i)->roll), (ptr + i)->name, &((ptr + i)->perc));
}
void output(struct student *ptr,int n)
{
     for (int i = 0; i < n; i++)
        printf("%d %s %lf\n", ((ptr + i)->roll), (ptr + i)->name, ((ptr + i)->perc));
}
int main()
{
    int n;
    cin>>n;

    struct student *ptr ;
    ptr=(struct student *)malloc(n*sizeof(struct student));

    input(ptr, n);
    output(ptr,n);
}
