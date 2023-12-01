#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create(){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  printf("Enter data: ");
  scanf("%d", &newNode -> data);
  int x;
  printf("Enter 0 to exit: ");
  scanf("%d", &x);
  if(x==0){
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
  } else{
    int choice;
    printf("Enter 1 to enter only left child \n2 to enter only right child \nOthers to enter both \nYour option -> ");
    scanf("%d", &choice);
    if(choice==1){
      newNode -> right = NULL;
      newNode -> left = create();
    }else if(choice==2){
      newNode -> left = NULL;
      newNode -> right = create();
    }else{
      newNode -> left = create();
      newNode -> right = create();
    }
    return newNode;
  }
}

void preorder(struct node *root){
  if(root!=NULL){
    printf("%d | ", root -> data);
    preorder(root -> left);
    preorder(root->right);
  }
}

void inorder(struct node *root){
  if(root!=NULL){
    inorder(root -> left);
    printf("%d | ", root -> data);
    inorder(root->right);
  }
}

void postorder(struct node *root){
  if(root!=NULL){
    postorder(root -> left);
    postorder(root->right);
    printf("%d | ", root -> data);
  }
}

int main(){
  struct node *root = NULL;
  root = create();
  printf("Preorder:\n");
    preorder(root);
  printf("\nInorder:\n");
    inorder(root);
  printf("\nPostorder:\n");
    postorder(root);

  return 0;
}

// Output
/*
Enter data: 1
Enter 0 to exit: 1
Enter 1 to enter only left child 
2 to enter only right child 
Others to enter both 
Your option -> 33
Enter data: 2
Enter 0 to exit: 1
Enter 1 to enter only left child 
2 to enter only right child 
Others to enter both 
Your option -> 3
Enter data: 4
Enter 0 to exit: 0
Enter data: 5
Enter 0 to exit: 0
Enter data: 3
Enter 0 to exit: 1
Enter 1 to enter only left child 
2 to enter only right child 
Others to enter both 
Your option -> 2
Enter data: 7
Enter 0 to exit: 0
Preorder:
1 | 2 | 4 | 5 | 3 | 7 | 
Inorder:
4 | 2 | 5 | 1 | 3 | 7 | 
Postorder:
4 | 5 | 2 | 7 | 3 | 1 | 
*/
