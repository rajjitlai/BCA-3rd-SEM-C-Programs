// Creation of link list and insert element at the beginning
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertAtBeginning(struct node **head)
{
	int newData;
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted: ");
	scanf("%d", &newData);
	newNode -> data = newData;
	newNode -> next = *head;
	*head = newNode;
}

void printValue(struct node *head){
	struct node *temp = head;
	while (temp != NULL){
		printf("%d\n", temp -> data);
		temp = temp -> next;
	}
}

int main(){
	struct node *head = NULL;
	insertAtBeginning(&head);
	printValue(head);
	return 0;
}