#include<stdio.h>
struct Student
{
    char name[100];
    int roll;
    char grade;
};
void read(struct Student s[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter details of Student %d\n",i+1);
        printf("Name: ");
        scanf("%s",s[i].name);
        fflush(stdin);
        printf("Roll no: ");
        scanf("%d",&s[i].roll);
        printf("Grade: ");
        scanf("%s",&s[i].grade);
    }

}
void sort(struct Student s[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i].roll>s[j].roll)
            {
                temp=s[j].roll;
                s[j].roll=s[i].roll;
                s[i].roll=temp;
            }
        }
    }
}
void display(struct Student s[], int n)
{
    printf("Name\tRoll no\tGrade");
    for(int i=0;i<n;i++)
    printf("%s\t%d\t%s\t",s[i].name,s[i].roll,s[i].grade);
}
int main()
{
    int n;
    printf("Enter no. of students: ");
    scanf("%d",&n);
    struct Student students[n];
    read(students, n);
    sort(students, n);
    display(students, n);
}
