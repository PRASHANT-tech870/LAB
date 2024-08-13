/*
initially head is null
create a new block of memory p
p of next points to head
head of prev points to p
and now head is p

*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

void insertFront(struct node **head, int ele)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next = p->prev = NULL;
    if (*head == NULL)
    {
        *head = p;
    }
    else
    {
        p->next = *head;
        (*head)->prev = p;
        *head = p;
    }
}

void insertEnd(struct node **head, int ele)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = ele;
    p->next = NULL;

    if (*head == NULL)
    {
        *head = p;
    }
    else
    {
        struct node *temp;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty LIst");
    }
    else
    {
        printf("\nList contents are: ");
        struct node *p;
        p = NULL;
        for (p = head; p != NULL; p = p->next)
        {
            printf("%d ", p->info);
        }
    }
}

int main()
{
    struct node *head;
    head = NULL;
    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 60);
    display(head);
}