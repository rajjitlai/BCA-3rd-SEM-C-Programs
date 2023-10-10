//Creation of link lists and give options to choose insertion at the beginning or insertion at the end and print the result
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertAtBeginning(struct node **head) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted: ");
	scanf("%d", &newNode -> data);
	newNode -> next = *head;
	*head = newNode;
}

void insertAtEnd(struct node **head){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *temp = *head;
	printf("Enter the value to be inserted: ");
	scanf("%d", &newNode -> data);
	newNode -> next = NULL;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	while (temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newNode;
}

void printValue(struct node *head){
	struct node *temp = head;
	while (temp != NULL){
		printf("%d\n", temp -> data);
		temp = temp -> next;
	}
}

int main(){
	int op;
	struct node *head = NULL;
	printf("Enter the type of insertion you want: \n1. At the beginning or \n2. At the end: \n");
	scanf("%d", &op);
	switch(op){
		case 1:
			insertAtBeginning(&head);
			insertAtBeginning(&head);
			insertAtBeginning(&head);
			printValue(head);
			break;
		case 2:
			insertAtEnd(&head);
			insertAtEnd(&head);
			insertAtEnd(&head);
			printValue(head);
			break;
		default:
			printf("You have entered an invalid option...");
			break;
	}
	return 0;
}