#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_SIZE 100

typedef struct
{
    float key;
} element;

element stack[MAX_SIZE];
int top = -1;

bool isEmpty()
{
    return (top==-1);
}

bool isFull()
{
    return(top==MAX_SIZE - 1);
}
void Push(element e) {
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


int isOperator(char ch)
{
    bool ret=false;
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        ret=true;
    return ret;
}
void evaluatePostfix(char *Postfix)
{
    int plen = strlen(Postfix);
    char cc;
    element ce;
    int pIndx;
    int OprnVal[125];
    for (int i = 0; i < 125; i++)
    {
        OprnVal[i] = 0;
    }

    for (pIndx = 0; pIndx < plen; pIndx++) {
        cc = Postfix[pIndx];
        if (isalpha(cc) && OprnVal[cc] == 0)
        {
            printf("Enter value for %c: ", cc);
            scanf("%d", &OprnVal[cc]);
        }
    }
    for (pIndx = 0; pIndx < plen; pIndx++)
        {

            cc = Postfix[pIndx];
        if (isalpha(cc))
            {
                ce.key = OprnVal[cc];
                Push(ce);
            }

        else if (isdigit(cc))
            {
            ce.key = (float)(cc - '0');
            Push(ce);
            }
        else if (isOperator(cc))
            {
                float op2 = pop().key;
                float op1 = pop().key;
                float ans;

            switch (cc)
            {
                case '+':
                    {
                        ans = op1 + op2;
                        ce.key=ans;
                        Push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '-':
                    {
                        ans = op1 - op2;
                        ce.key=ans;
                        Push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '*':
                    {
                        ans = op1 * op2;
                        ce.key=ans;
                        Push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '/':
                    {
                        if (op2 == 0)
                            {
                                printf("Division by zero\n");
                                exit(0);
                            }
                        ans= op1 / op2;
                        ce.key=ans;
                        Push(ce);
                        printf("%f\n",ans);
                        break;
                    }

            }
        }
        else
            {
                printf("Invalid Expression\n");
                return;
            }
    }

    if (top == 0)
        printf("Result: %f\n", stack[top].key);
    else
        printf("Invalid Expression\n");
}

int main()
{
    char Postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s",Postfix);

    evaluatePostfix(Postfix);

}
