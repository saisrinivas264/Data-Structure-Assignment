#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int doc)
{
    if(rear == MAX-1)
        printf("Queue Full\n");
    else
    {
        if(front == -1) front = 0;
        queue[++rear] = doc;
    }
}

void dequeue()
{
    if(front == -1)
        printf("No documents\n");
    else
    {
        printf("Printing document: %d\n", queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;
    if(front == -1)
        printf("Queue Empty\n");
    else
    {
        printf("Pending documents: ");
        for(i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int ch, doc;

    while(1)
    {
        printf("\n1.Add 2.Print 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter document id: ");
                scanf("%d", &doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
