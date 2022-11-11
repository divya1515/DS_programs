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
    for (int i = 0; i < 5; i++)
        scanf("%d%s%lf", &((ptr + i)->roll), (ptr + i)->name, &((ptr + i)->perc));
}
void output(struct student *ptr,int n)
{
     for (int i = 0; i < 5; i++)
        printf("%d %s %lf\n", ((ptr + i)->roll), (ptr + i)->name, ((ptr + i)->perc));
}
int main()
{
    struct student s[5];
    struct student *ptr = &s[0];
    input(ptr, 5);
    output(ptr,5);
}
