// Program to implement linked list concatenation
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

void insertElements(struct node **head, int val){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	struct node *temp = *head;
	newNode -> data = val;
	newNode -> next = NULL;
	if(*head==NULL){
		*head = newNode;
		return;	
	}
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newNode;
}

void printValue(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		printf(" %d |", temp->data);
		temp = temp -> next;
	}
}

void concatenateList(struct node *first, struct node *second){
	struct node *temp = first;
	while (temp  -> next != NULL)
		temp = temp -> next;
	temp -> next = second;
}

int main(){
	int i, n1, n2, val;
	struct node *head1 = NULL, *head2 = NULL;
	printf("Enter the number of list for 1st node: ");
	scanf("%d", &n1);
	for(i = 1; i <= n1; i++){
		printf("Enter the element %d: ", i);
		scanf("%d", &val);
		insertElements(&head1, val);
	}
	printf("\nThe default list for 1st node is: ");
	printValue(head1);
	printf("\n\nEnter the number of list for 2nd node: ");
	scanf("%d", &n2);
	for(i = 1; i <= n2; i++){
		printf("Enter the element %d: ", i);
		scanf("%d", &val);
		insertElements(&head2, val);
	}
	printf("\nThe default list for 2nd node is: ");
	printValue(head2);
	
	printf("\n\nThe list after concatenation is: ");
	concatenateList(head1, head2);
	printf("\n");
	printValue(head1);
	return 0;
}

