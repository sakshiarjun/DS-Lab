#include<stdio.h>
#define MAX_SIZE 100
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char key[100];
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

int isOperator(char o)
{
    bool ret=false;
    if(o=='+'||o=='-'||o=='*'||o=='^'||o=='/')
        ret=true;
    return ret;
}
void PostfixToInfix(char Postfix[])
{
    int plen=strlen(Postfix);
    char cs[2];
    char op1[100], op2[100];
    int pIndx;
    element ce;
    for(pIndx=0; pIndx<plen; pIndx++)
    {
        cs[0]=Postfix[pIndx];
        cs[1]='\0';
        if(isalnum(cs[0]))
        {
            strcpy(ce.key,cs);
            Push(ce);
        }
        if(isOperator(cs[0]))
        {
            strcpy(op2, pop().key);
            strcpy(op1, pop().key);
            strcpy(ce.key, "(");
            strcat(ce.key,op1);
            strcat(ce.key,cs);
            strcat(ce.key,op2);
            strcat(ce.key, ")");
        }
    }
    printf("Infix Expression: \n%s",pop().key);
}

int main()
{
    char s[MAX_SIZE];
    printf("Enter postfix expression: \n");
    scanf("%s",s);
    PostfixToInfix(s);
}
