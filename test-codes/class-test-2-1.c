// Create a link list with the following node:
/*
	rollno|mark|next }student
*/
// insert items through appending
// display all the students after deleting the last student
#include <stdio.h>
#include <stdlib.h>

struct student {
    int rollno;
    int mark;
    struct student* next;
};

void appendStudent(struct student** head, int rollno, int mark) {
    struct student* newStudent = (struct student*)malloc(sizeof(struct student));
    newStudent->rollno = rollno;
    newStudent->mark = mark;
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void displayStudents(struct student* head) {
    if (head == NULL) {
        printf("Student list is empty.\n");
        return;
    }

    struct student* current = head;
    while (current != NULL) {
        printf("Roll No: %d, Mark: %d\n", current->rollno, current->mark);
        current = current->next;
    }
}

void deleteLastStudent(struct student** head) {
    if (*head == NULL) {
        printf("Student list is empty. Cannot delete.\n");
        return;
    }

    struct student* current = *head;
    struct student* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);
}

int main() {
    struct student* head = NULL;
    int choice;

    do {
        printf("1. Add student\n2. Delete last student\n3. Display students\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int rollno, mark;
                printf("Enter Roll No: ");
                scanf("%d", &rollno);
                printf("Enter Mark: ");
                scanf("%d", &mark);
                appendStudent(&head, rollno, mark);
            }
            break;

            case 2:
                deleteLastStudent(&head);
                break;

            case 3:
                printf("List of students:\n");
                displayStudents(head);
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
