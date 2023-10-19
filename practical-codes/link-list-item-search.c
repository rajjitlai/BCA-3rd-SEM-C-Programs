#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertElement(struct node **head, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
	} else {
		struct node *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void searchElement(struct node **head, int val){
	if(*head == NULL){
		printf("The list is empty");
	}else{
		struct node *temp = *head;
		int f = 0;
		int pos = 1;
		while (temp != NULL){
			if(val == temp -> data)
			{
				f++;
				break;
			}
			temp = temp -> next;
			pos++;
		}
		if(f != 0){
			printf("Element %d found at %d", val, pos);
		}else{
			printf("Element not found...");
		}
	}
}

void printElement(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
}

int main(){
	int i, n, val, item;
	struct node *head = NULL;
	printf("Enter the number of elements you want to insert: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter the value for element %d: ", i + 1);
		scanf("%d", &val);
		insertElement(&head, val);
	}
	printf("The elements in the list are: ");
	printElement(head);
	printf("\nEnter the element you want to search: ");
	scanf("%d", &item);
	searchElement(&head, item);
	return 0;
}