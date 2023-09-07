#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_SZ 100

typedef struct {
    float key;
} element;

element stack[MAX_SZ];
int top = -1;

bool isEmpty()
{
    return (top==-1);
}

bool isFull()
{
    return(top==MAX_SZ - 1);
}
void push(element e) {
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

/*int isOperand(char ch) {
    return isalpha(ch);
}*/
int isOperator(char ch)
{
    bool ret=false;
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        ret=true;
    return ret;
}
void evaluatePostfix(char *postfix) {
    int plen = strlen(postfix);
    char cc;
    element ce;
    int pindex;
    int oprnval[125];
    for (int i = 0; i < 125; i++)
    {
        oprnval[i] = 0;
    }

    for (pindex = 0; pindex < plen; pindex++) {
        cc = postfix[pindex];
        //printf("%c\n",cc);
        if (isalpha(cc) && oprnval[cc] == 0)
        {
            printf("Enter value for %c: ", cc);
            scanf("%d", &oprnval[cc]);
            //printf("Op val is %d\n", oprnval[cc]);

        }
    }
    //printf("LEN= %d\n", plen);
    for (pindex = 0; pindex < plen; pindex++) {
        cc = postfix[pindex];
        //printf("CHAR IS %c \n",cc);
        if (isalpha(cc)) {
            ce.key = oprnval[cc];
            push(ce);
            printf("PUSH %d\n",oprnval[cc]);
        }
        else if (isdigit(cc))
            {
            ce.key = (float)(cc - '0');
            push(ce);
            }
        else if (isOperator(cc))
            {
            float op2 = pop().key;
            float op1 = pop().key;
            float ans;
            //printf("OP2 %d\n",op2);
            //printf("OP1 %d\n",op1);
            //printf("CHARACTER %c\n",cc);
            switch (cc)
            {
                case '+':
                    {
                        ans = op1 + op2;
                        ce.key=ans;
                        push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '-':
                    {
                        ans = op1 - op2;
                        ce.key=ans;
                        push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '*':
                    {
                        ans = op1 * op2;
                        ce.key=ans;
                        push(ce);
                        printf("%f\n",ans);
                        break;
                    }

                case '/':
                    {
                        if (op2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                        ans= op1 / op2;
                        ce.key=ans;
                        push(ce);
                        printf("%f\n",ans);
                        break;
                    }

            }
            //push(ce);
        } else {

            printf("Invalid Expression\n");
            return;
        }
    }

    if (top == 0) {
        printf("Result: %f\n", stack[top].key);
    } else {
        printf("Invalid Expression\n");
    }
}

int main() {
    char postfix[MAX_SZ];

    printf("Enter a postfix expression: ");
    scanf("%s",postfix);

    evaluatePostfix(postfix);

}
