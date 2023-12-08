// Program to implement queue using Multiple Stacks

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *stack1;
    struct node *stack2;
};

void enqueue(struct queue *q)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;

    if (q->stack1 == NULL)
        q->stack1 = newNode;
    else
    {
        struct node *temp = q->stack1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void dequeue(struct queue *q)
{
    if (q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    if (q->stack2 == NULL)
    {
        while (q->stack1 != NULL)
        {
            struct node *temp = q->stack1;
            q->stack1 = q->stack1->next;
            temp->next = q->stack2;
            q->stack2 = temp;
        }
    }

    struct node *temp = q->stack2;
    if (q->stack2 != NULL)
    {
        q->stack2 = q->stack2->next;
        printf("The deleted element is: %d\n", temp->data);
        free(temp);
    }
    else
    {
        printf("Queue is empty\n");
    }

    temp = q->stack1;
    while (temp != NULL)
    {
        q->stack1 = temp->next;
        free(temp);
        temp = q->stack1;
    }
}

void display(struct queue *q)
{
    struct node *temp = q->stack1;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = q->stack2;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct queue q;
    int n;
    q.stack1 = NULL;
    q.stack2 = NULL;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        enqueue(&q);
    }

    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}

// Output
/*
Enter the size of the queue: 5
Enter the data: 23
Enter the data: 99
Enter the data: 45
Enter the data: 15
Enter the data: 76
Queue elements: 23 99 45 15 76 
The deleted element is: 76
Queue elements: 15 45 99 23 
*/