/* Program to create a link list and give options to insert data at the beginning, at any position or at the end - HARD*/
/* Accept the data in the main part of the program */
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertAtBeginning(struct node **head, int val) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> data = val;
	newNode -> next = *head;
	*head = newNode;
}

void insertAtAnyPos(struct node **head, int val, int pos) {
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = val;
	if(*head == NULL || pos == 0) {
		newNode -> next = *head;
		*head = newNode;
	} else {
		temp = *head;
		for (int i = 1; i < pos-1 && temp != NULL; i++) {
			temp = temp->next;
		}
		if (temp == NULL) {
			printf("Invalid position. Element cannot be inserted.\n");
		} else {
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}

void insertAtEnd(struct node **head, int val) {
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

void printValue(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
}

int main() {
	int op, pos, val;
	struct node *head = NULL;

	while (1) {
		printf("Enter the value to be inserted: ");
		scanf("%d", &val);
		printf("Choose an option:\n1. Insert at the beginning\n2. Insert at any position\n3. Insert at the end\n4. Exit\nOption: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				insertAtBeginning(&head, val);
				break;
			case 2:
				printf("Enter the position where you want to insert: ");
				scanf("%d", &pos);
				insertAtAnyPos(&head, val, pos);
				break;
			case 3:
				insertAtEnd(&head, val);
				break;
			case 4:
				printf("Exiting the program....\n");
				exit(0);
			default:
				printf("Invalid option. Please choose a valid option.\n");
				break;
		}
		printf("Updated Linked List: ");
		printValue(head);
		printf("\n");
	}
	return 0;
}

// Output:
/*
Enter the value to be inserted: 21
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 1
Updated Linked List: 21 |
Enter the value to be inserted: 6
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 1
Updated Linked List: 6 | 21 |
Enter the value to be inserted: 78
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 3
Updated Linked List: 6 | 21 | 78 |
Enter the value to be inserted: 67
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 2
Enter the position where you want to insert: 3
Updated Linked List: 6 | 21 | 67 | 78 |
Enter the value to be inserted: 21
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 2
Enter the position where you want to insert: 10
Invalid position. Element cannot be inserted.
Updated Linked List: 6 | 21 | 67 | 78 |
Enter the value to be inserted: 21
Choose an option:
1. Insert at the beginning
2. Insert at any position
3. Insert at the end
4. Exit
Option: 4
Exiting the program....
 */