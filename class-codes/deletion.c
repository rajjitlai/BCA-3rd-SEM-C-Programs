// P11. Program to delete items from the link list 
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertElement(struct node **head, int val){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
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

void delAtBegin(struct node **head){
	if(*head == NULL){
		printf("The list is empty");
	}
	else{
		(*head) = (*head) -> next;
	}
}

void delAtEnd(struct node **head){
	if(*head == NULL){
		printf("The list is empty");
	}
	else{
		struct node *temp = *head;
		temp = *head;
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = NULL;
	}
}

void delAtAnyPos(struct node **head, int pos){
	int i;
	if(*head == NULL){
		printf("The list is empty");
	}
	else{
		struct node *temp = *head;
		for(i = 1; i< pos-1 && temp != NULL; i++){
			temp = temp -> next;
		}
		temp -> next = temp -> next -> next;
	}
}

void searchnDel(struct node **head, int val){
	if(*head == NULL){
		printf("The list is empty");
	}
	else{
		int f = 0, c = 0;
		struct node *temp = *head;
		while(temp != NULL){
			c++;
			if(val == temp -> data){			
				f++;
				break;
			}
			temp = temp -> next;
		}
		if(f != 0){
			printf("Element found...");
			delAtAnyPos(head, c);
			printf("\nElement %d deleted successfully from position %d", val, c);
		}else{
			printf("Element not found...");
		}
	}
}

void printValue(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
}

int main(){
	int op, pos, val, n, i;
	struct node *head = NULL;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{	
		printf("Enter the elements: ");
		scanf("%d", &val);
		insertElement(&head, val);
	}	
	printf("\nThe linked list is: ");
	printValue(head);
	
	while (1) {
		printf("\n\nChoose an option:\n1. Deletion from the beginning \n2. Deletion from the end\n3. Deletion from any position \n4. Search an element and delete it \n5. Display the updated linked list \n6. Exit the program\nOption: ");
		scanf("%d", &op);
		
		switch(op){
			case 1: 
				delAtBegin(&head);
				break;
			case 2:
				delAtEnd(&head);
				break;
			case 3:
				printf("Enter the position of element item to be deleted: ");
				scanf("%d", &pos);
				delAtAnyPos(&head, pos);
				printf("\nItem deleted successfully...");
				break;
			case 4:
				printf("Enter the element to be searched: ");
				scanf("%d", &val);
				searchnDel(&head, val);
				break;
			case 5:
				printf("\nThe updated linked list is: ");
				printValue(head);
				break;
			case 6:
				printf("Exitting the program...");
				exit(0);
			defaut:
				printf("Invalid option. Please enter a valid one");
				break;
		}	
	}
	return 0;
}
