#include <stdio.h>

int rear = -1;
int front = -1;
int ticketsTaken = 0;

void recordTicket(int arr[], int n) {
	if (ticketsTaken >= n) {
		printf("All members' tickets have been recorded. Cannot record more.\n");
	} else if (rear == -1 && front == -1) {
		rear = front = 0;
		printf("Give the ticket no.: ");
		scanf("%d", &arr[rear]);
		ticketsTaken++;
	} else if (front == (rear + 1) % n) {
		printf("All the tickets are taken. Please come back later...\n");
	} else {
		rear = (rear + 1) % n;
		printf("Give the ticket no.: ");
		scanf("%d", &arr[rear]);
		ticketsTaken++;
	}
}

void displayTickets(int arr[], int n) {
	if (front == -1 && rear == -1) {
		printf("No tickets recorded.\n");
	} else {
		printf("\nRecorded Tickets:\n");
		int i = front;
		int slNo = 1;
		while (i != rear) {
			printf("%d. Ticket no: %d\n", slNo, arr[i]);
			i = (i + 1) % n;
			slNo++;
		}
		printf("%d. Ticket no: %d\n", slNo, arr[rear]);
	}
}

int main() {
	int n;
	printf("Enter the number of tickets: ");
	scanf("%d", &n);
	int arr[n];
	int mem;
	printf("Enter the number of members who can stand in line: ");
	scanf("%d", &mem);

	if (n < mem) {
		printf("Only %d members are allowed.\n", n);
		printf("Giving tickets to only %d members.\n", n);
		mem = n;
	}

	printf("Menu:\n");
	printf("1. Record Ticket\n");
	printf("2. Display Tickets\n");
	printf("3. Record More Tickets\n");
	printf("4. Exit\n");

	int choice;
	do {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				if (ticketsTaken >= mem) {
					printf("All members' tickets have been recorded. Cannot record more.\n");
				} else {
					recordTicket(arr, n);
				}
				break;
			case 2:
				displayTickets(arr, n);
				break;
			case 3:
				if (mem < n) {
					printf("There are %d remaining tickets...\n", n - mem);
					mem++;
					recordTicket(arr, n);
				} else {
					printf("All members' tickets have been recorded. Cannot record more.\n");
				}
				break;
			case 4:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice. Try again.\n");
		}
	} while (choice != 4);

	return 0;
}
