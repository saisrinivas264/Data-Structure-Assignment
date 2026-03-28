#include <stdio.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int isMatching(char open, char close)
{
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}

int main()
{
    char exp[100];
    int i = 0;

    printf("Enter expression: ");
    scanf("%s", exp);

    while(exp[i] != '\0')
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top == -1 || !isMatching(pop(), exp[i]))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
        i++;
    }

    if(top == -1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced\n");

    return 0;
}