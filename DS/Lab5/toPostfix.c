#include<stdio.h>
#define MAX_SIZE 50
#include<stdbool.h>
#include<stdlib.h>
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
element peak()
{
    return stack[top];
}


int precedence(char ch)
{
    int ret=-1;
    switch(ch)
    {
    case '^':
        ret=3;
        break;
    case '*':
    case '/':
        ret=2;
        break;
    case '+':
    case '-':
        ret=1;
        break;
    }
    return ret;
}





bool isOperand(char ch)
{
    bool ret=false;
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        ret=true;
    return ret;
}
void infixToPostfix(char infix[])
{
    int ilen=strlen(infix);
    char Postfix[MAX_SIZE];
    char cc;
    element ce;
    int iIndx, pIndx=0;
    for(iIndx=0; iIndx<ilen; iIndx++)
    {
        cc=infix[iIndx];
        if(isOperand(cc))
            Postfix[pIndx++]=cc;
        else if(cc=='(')
        {
            ce.key=cc;
            Push(ce);
        }
        else if(cc==')')
        {
            while(!isEmpty() && peak().key!='(')
                    {Postfix[pIndx++]=pop().key;}
            if(isEmpty())
            {
                printf("Invalid");
                free(Postfix);
                return;
            }
            else if (peak().key=='(')
                pop();
        }
        else
        {
            while(precedence(peak().key)>=precedence(cc))
                {
                    Postfix[pIndx++]=pop().key;
                }
            ce.key=cc;
            Push(ce);
        }
    }

    while(!isEmpty())
    {
        Postfix[pIndx++]=pop().key;
    }
    Postfix[pIndx]='\0';
    printf("Postfix Expression: %s", Postfix);
}

int main()
{
    char s[MAX_SIZE];
    printf("Enter infix expression: \n");
    scanf("%s",s);
    infixToPostfix(s);
}



