#include <stdio.h>

int rear = -1;
int front = -1;
int ticketsTaken = 0;

void recordTicket(int arr[], int n) {
    if (ticketsTaken >= n) {
        printf("All tickets have been taken. Do you want to start over? (Y/N): ");
        char startOver;
        scanf(" %c", &startOver);
        if (startOver == 'Y' || startOver == 'y') {
            rear = front = -1;
            ticketsTaken = 0;
            printf("Starting over...\n");
        } else {
            printf("Exiting...\n");
        }
    }

    if (rear == -1 && front == -1) {
        rear = front = 0;
    } else if (front == (rear + 1) % n) {
        printf("All the tickets are taken. Please come back later...\n");
    } else {
        rear = (rear + 1) % n;
    }

    printf("Give the ticket no.: ");
    scanf("%d", &arr[rear]);
    ticketsTaken++;
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

    char startOver = 'N';

    do {
        printf("Menu:\n");
        printf("1. Record Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Start Over\n");
        printf("4. Exit\n");

        int choice;

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordTicket(arr, n);
                break;
            case 2:
                displayTickets(arr, n);
                break;
            case 3:
                printf("Do you want to start over? (Y/N): ");
                scanf(" %c", &startOver);
                if (startOver == 'Y' || startOver == 'y') {
                    rear = front = -1;
                    ticketsTaken = 0;
                    printf("Starting over...\n");
                } else {
                    printf("Exiting...\n");
                    return 0;
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}
