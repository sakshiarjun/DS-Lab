#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct
{
    char key;
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
    int i=0,flag=1,l;
    char str[100];
    printf("Enter String to check Palindrome: \n");
    scanf("%[^\n]",str);
    l=strlen(str);
   // printf("Lnegth= %d",l);
    while(str[i]!='\0')
    {
        char c=str[i];
        element e;
        e.key=c;
        Push(e);
        i++;
    }
    i=0;
    while(str[i]!='\0')
    {
        if(pop().key!=str[i])
        {
            flag=0;
            break;
        }
        i++;
    }
    if(flag==0)
        printf("Not a Palindrome");
    else
        printf("Palindrome");
}


