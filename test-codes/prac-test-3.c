#include <stdio.h>

int rear = -1;
int front = -1;

int recordTicket(int arr[], int n, int *serial) {
    if (rear == -1 && front == -1) {
        rear = front = 0;
        printf("Give the ticket no: ");
        scanf("%d", &arr[rear]);
    } else if (front == (rear + 1) % n) {
        printf("All the tickets are taken. Please come back later.\n");
        return 0; // Return 0 to indicate no more tickets can be recorded
    } else {
        rear = (rear + 1) % n;
        printf("Give the ticket no: ");
        scanf("%d", &arr[rear]);
    }
    (*serial)++; // Increment the serial number
    return 1; // Return 1 to indicate that a ticket has been recorded
}

void displayTickets(int arr[], int front, int rear, int n) {
    printf("Recorded Tickets: \n");
    if (front == -1 && rear == -1) {
        printf("No tickets recorded.\n");
    } else {
        int i = front;
        int serial = 1; // Initialize serial number
        do {
            printf("Serial No: %d, Ticket No: %d\n", serial, arr[i]);
            i = (i + 1) % n;
            serial++; // Increment the serial number
        } while (i != (rear + 1) % n);
    }
}

int main() {
    int n;
    printf("Enter the number of tickets: ");
    scanf("%d", &n);

    int mem;
    printf("Enter the number of members who can stand in line: ");
    scanf("%d", &mem);

    if (n < mem) {
        printf("The ticket accommodation cannot be greater than %d\n", n);
        mem = n; // Reduce the number of members to the available tickets
    }

    int arr[n]; // Array to store ticket numbers
    int ticketRecorded = 0; // Counter to keep track of recorded tickets
    int serial = 0; // Initialize serial number

    while (ticketRecorded < mem) {
        int result = recordTicket(arr, n, &serial);
        if (result == 1) {
            ticketRecorded++;
            printf("Ticket recorded successfully.\n");
        } else {
            break; // Stop recording tickets when no more can be recorded
        }
    }

    printf("All tickets for %d members have been recorded. Thank you!\n", mem);

    displayTickets(arr, front, rear, n);

    // Check if more people want tickets
    while (ticketRecorded < n) {
        char moreTickets;
        printf("Do more people want to get tickets? (y/n): ");
        scanf(" %c", &moreTickets);

        if (moreTickets == 'n' || moreTickets == 'N') {
            break;
        } else if (moreTickets == 'y' || moreTickets == 'Y') {
            int result = recordTicket(arr, n, &serial);
            if (result == 1) {
                ticketRecorded++;
                printf("Ticket recorded successfully.\n");
            } else {
                break; // Stop recording tickets when no more can be recorded
            }
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    if (ticketRecorded >= n) {
        char startOver;
        printf("All available tickets are taken. Do you want to start over? (y/n): ");
        scanf(" %c", &startOver);

        if (startOver == 'y' || startOver == 'Y') {
            ticketRecorded = 0; // Reset the ticket counter
            rear = front = -1; // Reset the queue
        }
    }

    printf("No more tickets are available. Thank you!\n");

    return 0;
}
