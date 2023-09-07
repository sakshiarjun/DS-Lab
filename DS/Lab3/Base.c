#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct
{
    int key;
}element;
element stack[MAX_SIZE];
int top=-1;
bool isEmpty()
{
    return (top==-1);
}
bool isFull()
{
    return(top==MAX_SIZE - 1);
}
void Push(element e)
{
    stack[++top]=e;
    if(isFull())
    {
        printf("Error");
        return;
    }
}
element pop()
{
    if(isEmpty())
    {
        ;
    }
    return(stack[top--]);
}
int main()
{
    int b,n,r,temp;
    printf("Enter base system: ");
    scanf("%d",&b);
    printf("Enter number: ");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        r=n%b;
        element e;
        e.key=r;
        Push(e);
        n=n/b;
    }
    //printf("%d is %d when base is %d",temp,r,b);
    while(top>=0)
        printf("%d",pop());

}
