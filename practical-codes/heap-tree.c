// Heap - Implementation - Max Heap

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// swapping the values
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insertion
struct node *addNode(struct node *root, int d){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL){
        root = newNode;
        return root;
    }
    else{
        if(root ->left ==NULL){
            if(d < root->data)
                root->left = addNode(root->left, d);
            else{
                swap(&(root->data), &d);
                root->left = addNode(root->left, d);
            }
        }
        else{
            if(d < root->data)
                root->right = addNode(root->right, d);
            else{
                swap(&(root->data), &d);
                root->right = addNode(root->right, d);
            }
        }
    }
    return root;
}

// traversal
void display(struct node *root){
    if(root == NULL)
        return;
    printf("%d | ", root->data);
    display(root->left);
    display(root->right);
}

int main(){
    int d, n;
    struct node *root = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        printf("Enter the element: ");
        scanf("%d", &d);
        root = addNode(root, d);
    }

    printf("\nThe traversal of the elements: \n");
    display(root);

    return 0;
}

// Output:
/*
Enter the number of elements: 5
Enter the element: 23
Enter the element: 20
Enter the element: 21
Enter the element: 19
Enter the element: 18
The traversal of the elements: 
23 | 20 | 21 | 19 | 18 | 
*/
