// Program to implement Stack Dynamically
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

void push(struct node **top){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newNode->data);
	newNode -> next = *top;
	*top=newNode;
}

void pop(struct node **top){
	if(*top==NULL)
		printf("Stack underflow");
	else{
		struct node *temp = *top;
		printf("\n\nThe deleted item is %d", (*top)-> data);
		*top = (*top)->next;
		free(temp);
		printf("\n");
	}
}

void display(struct node *top){
	struct node *temp = top;
	if(temp==NULL)
		printf("Stack underflow");
	else{
		while(temp!=NULL)
		{
			printf("%d | ", temp->data);
			temp = temp -> next;
		}
	}
}

int main(){
	struct node *top = NULL;
	push(&top);
	push(&top);
	display(top);
	pop(&top);
	display(top);
	return 0;
}

// Output
/*
Enter the data: 4
Enter the data: 2
2 | 4 |

The deleted item is 2
4 |
*/