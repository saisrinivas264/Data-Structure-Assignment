#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for(i=n-1; i>=0; i--)
    {
        while(top != -1 && peek() <= arr[i])
            pop();

        if(top == -1)
            printf("%d -> -1\n", arr[i]);
        else
            printf("%d -> %d\n", arr[i], peek());

        push(arr[i]);
    }

    return 0;
}
