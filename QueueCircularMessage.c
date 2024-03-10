#include <stdio.h>
#include <string.h>
#define MAX 5
struct queue
{

    char a[MAX][100];
    int rear;
    int front;

} cq;

void enqueue(char *msg)
{
    if (cq.front == (cq.rear + 1) % MAX)
    {
        printf("Overflow\n");
        return;
    }

    if (cq.front == -1)
    {
        cq.front = 0;
    }
    cq.rear = (cq.rear + 1) % MAX;
    // cq.rear++;
    strcpy(cq.a[cq.rear], msg);
}

void dequeue()
{
    if (cq.front == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Deleted: %s\n", cq.a[cq.front]);
    if (cq.front == cq.rear)
    {
        cq.front = cq.rear = -1;
    }
    else
    {
        cq.front = (cq.front + 1) % MAX;
    }
}

void display()
{
    if (cq.front == -1)
    {
        printf("Underflow\n");
        return;
    }
    int i;
    if (cq.rear >= cq.front)
    {
        for (i = cq.front; i <= cq.rear; i++)
        {
            printf("%s\n", cq.a[i]);
        }
    }
    else
    {
        for (i = cq.front; i < MAX; i++)
        {
            printf("%s\n", cq.a[i]);
        }

        for (i = 0; i <= cq.rear; i++)
        {
            printf("%s\n", cq.a[i]);
        }
    }
}

int main()
{
    cq.front = cq.rear = -1;
    enqueue("a");
    enqueue("b");
    enqueue("c");
    enqueue("d");
    enqueue("e");
    display();
    dequeue();
    dequeue();
    dequeue();
    enqueue("f");
    enqueue("g");
    display();

    return 0;
}