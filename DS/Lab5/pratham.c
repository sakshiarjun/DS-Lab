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

element pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
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
    for (pindex = 0; pindex < plen; pindex++) {
        cc = postfix[pindex];
        //printf("CHAR IS %c \n",cc);
        if (isalpha(cc)) {
            ce.key = oprnval[cc];
            push(ce);
        } else if (isdigit(cc)) {
            ce.key = (int)(cc - '0');
            push(ce);
        } else if (isOperator(cc)) {
            float op2 = pop().key;
            float op1 = pop().key;
            switch (cc) {
                case '+':
                    {
                        ce.key = op1 + op2;
                        push(ce);
                        break;
                    }

                case '-':
                    {
                        ce.key = op1 - op2;
                        push(ce);
                        break;
                    }

                case '*':
                    {
                        ce.key = op1 * op2;
                        push(ce);
                        break;
                    }

                case '/':
                    {
                        if (op2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    ce.key = op1 / op2;
                    push(ce);
                    break;
                    }

            }
            //push(ce);
        }
        else {
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
    //fgets(postfix, sizeof(postfix), stdin);
    scanf("%s",postfix);

    evaluatePostfix(postfix);

}
