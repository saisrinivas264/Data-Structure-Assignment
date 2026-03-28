#include <stdio.h>

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if((rear+1)%SIZE == front)
    {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear+1)%SIZE;
    cq[rear] = val;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front+1)%SIZE;
}

void peek()
{
    if(front == -1)
        printf("Empty\n");
    else
        printf("Front: %d\n", cq[front]);
}

void display()
{
    int i = front;

    if(front == -1)
    {
        printf("Empty\n");
        return;
    }

    printf("Queue: ");
    while(1)
    {
        printf("%d ", cq[i]);
        if(i == rear)
            break;
        i = (i+1)%SIZE;
    }
    printf("\n");
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}