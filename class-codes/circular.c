// Program to implement Circular linkd list
#include<stdio.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};

void insBeg(struct node **head){
	struct node *newNode = (struct node *malloc(sizeof(struct node));
	struct node *temp;
	printf("Enter data (beginning): ");
	scanf("%d", &newNode -> data);
	if(*head == NULL)
	{
		newNode -> next = newNode;
		*head = newNode;
	} else{
		temp = *head;
		while(temp -> next != *head)
			temp = temp -> next;
		temp -> next = newNode;
		newNode -> next -> *head;
		*head = newNode;
	}
}

void insEnd(struct node **head){
	struct node *newNode = (struct node *malloc(sizeof(struct node));
	struct node *temp;
	printf("Enter data (end): ");
	scnf("%d", &newNode -> data);
	if(*head == NULL){
		newNode -> next = *head;
	}else{
		temp = *head;
		while(temp ->next !=head)
			temp = temp -> next;
		temp -> next = newNode;
		newNode -> next = head;
	}
}

