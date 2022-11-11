#include <stdio.h>
#include <malloc.h>
struct Student
{
    int RollNo;
    char Name[50];
    double perc;
};

void Input(struct Student *ptr)
{
    scanf("%d%s%lf", &(ptr->RollNo), ptr->Name, &(ptr->perc));
}

void OutPut(struct Student *ptr)
{
    printf("%d %s %lf",ptr->RollNo, ptr->Name, ptr->perc);
    printf("\n");
}

int main()
{
    struct Student *p;
    printf("Enter Student Details: ");

    p = (struct Student *)malloc(sizeof(struct Student));

    Input(p);
    OutPut(p);
}
