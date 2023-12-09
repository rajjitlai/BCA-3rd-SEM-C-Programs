// Program to implement AVL Tree

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

struct node *CreateNode(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; // Initialize height to 1
    return newnode;
}

int Balancedfactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// RR
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// LR
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insertion
struct node *insert(struct node *node, int key)
{
    // Perform standard BST insertion
    if (node == NULL)
    {
        return CreateNode(key);
    }

    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        // Duplicate keys are not allowed
        return node;
    }

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = Balancedfactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->data)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotation needed
    return node;
}
// Searching module
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

// inorder predecessor
struct node *inorderPre(struct node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return NULL;
    }
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Deletion module
struct node *deleteNode(struct node *root, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > d)
        root->left = deleteNode(root->left, d);
    else if (root->data < d)
        root->right = deleteNode(root->right, d);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = inorderPre(root);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}

// Function to print the preorder traversal of the tree
void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d|", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d|", root->data);
        inorderTraversal(root->right);
    }
}

// Function to print the postorder traversal of the tree
void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d|", root->data);
    }
}

// Main function of the AVL tree
int main()
{
    struct node *root = NULL;
    int n, i, num;
    printf("Enter no of data:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter data:");
        scanf("%d", &num);
        root = insert(root, num);
    }

    // Searching
    int srNum;
    struct node *srItem;
    printf("\nSearching part\n");
    printf("\nEnter the data for which you want to search: ");
    scanf("%d", &srNum);
    srItem = search(root, srNum);
    if (srItem != NULL)
    {
        printf("Element found");
    }
    else
    {
        printf("Element not found in the tree");
    }
 // Traversal
    printf("\nBefore deletion:\n");
    printf("Preorder:\n");
    preorderTraversal(root);
    printf("\nInorder:\n");
    inorderTraversal(root);
    printf("\nPostoder:\n");
    postorderTraversal(root);
    // Deletion
    int delNum;
    printf("\nDeletion part\n");
    printf("\nEnter the data for which you want to delete: ");
    scanf("%d", &delNum);
    root = deleteNode(root, delNum);
    
    // Traversal
    printf("\nAfter deletion:\n");
    printf("Preorder:\n");
    preorderTraversal(root);
    printf("\nInorder:\n");
    inorderTraversal(root);
    printf("\nPostoder:\n");
    postorderTraversal(root);

    return 0;
}
/* 
Output:

Enter no of data:4
Enter data:1
Enter data:2
Enter data:3
Enter data:4
Searching part

Enter the data for which you want to search: 2
Element found
Before deletion:
Preorder:
2|1|3|4|
Inorder:
1|2|3|4|
Postoder:
1|4|3|2|
Deletion part

Enter the data for which you want to delete: 3
After deletion:
Preorder:
2|1|4|
Inorder:
1|2|4|
Postoder:
1|4|2|

*/
