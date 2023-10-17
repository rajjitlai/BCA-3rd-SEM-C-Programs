// Program to create a link list with the details - struct student, int roll no, char grade and dislay the roll numbers which have grade B

#include<stdio.h>
#include<stdlib.h>

struct student {
	int rollNo;
	char grade[2];
	struct student *next;
};

void insertDetails(struct student **head, int roll) {
	struct student *newNode = (struct student *)malloc(sizeof(struct student));
	newNode -> rollNo = roll;
	printf("Grade: ");
	scanf("%s", &newNode -> grade);
	printf("\n");
	newNode -> next = NULL;

	if(*head == NULL) {
		*head = newNode;
	} else {
		struct student *temp = *head;
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = newNode;
	}
}

void displayRoll(struct student *head){
	struct student *temp = head;
	printf("The roll numbers are: \n");
	while(temp != NULL){
		printf(" %d | ", temp -> rollNo);
		temp = temp -> next;
	}
}

void displayGradeB(struct student *head){
	struct student *temp = head;
	while (temp != NULL){
		// if((*temp -> grade) == 'B') // this works
		if(*temp -> grade == 66) // this also works where the ASCII code of B is 66
			printf(" Roll No - %d, Grade - %s | ", temp -> rollNo, temp -> grade);
		temp = temp -> next;
	}
}

int main(){
	int roll, i;
	char grade[2];
	struct student *head = NULL;
	printf("Enter the roll numbers with their grade: \n");
	for(i = 1; i <= 5; i++)
	{
		printf("%d Roll No: ", i);
		scanf("%d", &roll);
		insertDetails(&head, roll);
	}
	displayRoll(head);
	printf("\n\nThe roll numbers with the grade B are: \n");
	displayGradeB(head);
	
	return 0;
}

// Output
/*
Enter the roll numbers with their grade:
1 Roll No: 1
Grade: B

2 Roll No: 2
Grade: A

3 Roll No: 3
Grade: C

4 Roll No: 4
Grade: B

5 Roll No: 5
Grade: D

The roll numbers are:
 1 |  2 |  3 |  4 |  5 |

The roll numbers with the grade B are:
 Roll No - 1, Grade - B |  Roll No - 4, Grade - B |
*/