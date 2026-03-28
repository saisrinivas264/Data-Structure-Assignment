#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char ch)
{
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

// pop function
char pop()
{
    if(top == -1)
        return '\0';
    else
        return stack[top--];
}

int main()
{
    char str[100], rev[100];
    int i = 0;

    printf("Enter string: ");
    scanf("%s", str);

    // push all characters
    while(str[i] != '\0')
    {
        push(str[i]);
        i++;
    }

    i = 0;
    // pop to reverse
    while(top != -1)
    {
        rev[i++] = pop();
    }
    rev[i] = '\0';

    printf("Reversed String: %s\n", rev);

    return 0;
}

