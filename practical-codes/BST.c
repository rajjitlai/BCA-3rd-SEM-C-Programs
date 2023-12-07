#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
//	char data[20];
	struct node *left;
	struct node *right;
};

// creation
struct node *create(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data=num;
	newNode ->left=NULL;
	newNode->right=NULL;
	return newNode;
}

// searching and checking
struct node *search(struct node *root, int key) {
	if(root==NULL||root->data==key) {
		return root;
	} else if(key<root->data) {
		search(root->left, key);
	} else {
		search(root->right, key);
	}
}

// insertion
struct node *insert(struct node *root, int num) {
	if(root==NULL) {
		return create(num);
	} else if(num<root->data)
		root->left=insert(root->left, num);
	else
		root->right=insert(root->right, num);
	return root;
}

// traversal
void preorder(struct node *root) {
	if(root!=NULL) {
		printf("%d | ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root) {
	if(root!=NULL) {
		inorder(root->left);
		printf("%d | ", root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root) {
	if(root!=NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d | ", root->data);
	}
}

// inorder predecessor
struct node *inorderPre(struct node *root) {
	root = root ->left;
	while(root->right!=NULL)
		root=root->right;
	return root;
}

// deletion
struct node *deleteNode(struct node *root, int d) {
	if(root==NULL) {
		return NULL;
	} else if(root->left==NULL && root->right==NULL) {
		free(root);
		return NULL;
	} else {
		if(root->data > d)
			root->left = deleteNode(root->left, d);
		else if(root->data < d)
			root->right = deleteNode(root->right, d);
		else {
			struct node *temp = inorderPre(root);
			root->data = temp->data;
			root->left=deleteNode(root, temp->data);
		}
		return root;
	}
	
}

int main() {
	struct node *root = NULL;
	int n, num;
	// insertion
	printf("Enter the number of items: ");
	scanf("%d", &n);
	for(int i=1; i<= n; i++) {
		printf("Enter the data: ");
		scanf("%d", &num);
		root = insert(root, num);
	}
	// Traversal
	printf("\nbefore deletion:\n");
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPostoder:\n");
	postorder(root);
	// Searching
	int srNum;
	struct node *srItem;
	printf("\n\n\tSearching part\n");
	printf("\nEnter the data for which you want to search: ");
	scanf("%d", &srNum);
	srItem = search(root, srNum);
	if(srItem != NULL) {
		printf("Element found");
	} else {
		printf("Element not found in the tree");
	}
	// Deletion
	int delNum;
	printf("\n\n\tDeletion part\n");
	printf("\nEnter the data for which you want to delete: ");
	scanf("%d", &delNum);
	root = deleteNode(root, delNum);
	// Traversal
	printf("\nAfter deletion:\n");
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPostoder:\n");
	postorder(root);

	return 0;
}

// Output
/*
Enter the number of items: 5
Enter the data: 30
Enter the data: 20
Enter the data: 10
Enter the data: 25
Enter the data: 23

before deletion:
Preorder:
30 | 20 | 10 | 25 | 23 |
Inorder:
10 | 20 | 23 | 25 | 30 |
Postoder:
10 | 23 | 25 | 20 | 30 |

        Searching part

Enter the data for which you want to searh: 45
Element not found in the tree

        Deletion part

Enter the data for which you want to delete: 10

After deletion:
Preorder:
30 | 20 | 25 | 23 |
Inorder:
20 | 23 | 25 | 30 |
Postoder:
23 | 25 | 20 | 30 |
*/








