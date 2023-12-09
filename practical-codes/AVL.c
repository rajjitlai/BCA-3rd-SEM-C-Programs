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
    // Print the preorder traversak of the AVL tree
    printf("Inorder traversal of the AVL tree: ");
    preorderTraversal(root);

    // Print the inorder traversal of the AVL tree
    printf("\nInorder traversal of the AVL tree: ");
    inorderTraversal(root);

    // Print the postorder traversal of the AVl tree
    printf("\nPostorder traversal of the AVL tree: ");
    postorderTraversal(root);

    return 0;
}
/*
Output:

Enter no of data:6
Enter data:55
Enter data:25
Enter data:65
Enter data:9
Enter data:8
Enter data:15
Inorder traversal of the AVL tree: 25|9|8|15|55|65|  
Inorder traversal of the AVL tree: 8|9|15|25|55|65|  
Postorder traversal of the AVL tree: 8|15|9|65|55|25|

  */
