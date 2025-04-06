#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the binary search tree
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the binary search tree
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to find the minimum value node in a binary search tree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the binary search tree
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Function to count the total number of leaf nodes in a binary search tree
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to find the height of a binary search tree
int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to count the total number of nodes from the right side of the root
int countNodesOnRight(struct Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }

    return 1 + countNodesOnRight(root->right) + countNodesOnRight(root->left);
}

// Function to print the inorder traversal of the binary search tree
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    // Inserting keys into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search operation
    int searchKey = 40;
    struct Node *searchResult = search(root, searchKey);
    if (searchResult != NULL)
    {
        printf("Key %d found in the BST.\n", searchKey);
    }
    else
    {
        printf("Key %d not found in the BST.\n", searchKey);
    }

    // Delete operation
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("Inorder traversal after deleting %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    // Counting leaf nodes
    printf("Total number of leaf nodes: %d\n", countLeafNodes(root));

    // Finding height of the BST
    printf("Height of the BST: %d\n", findHeight(root));

    // Counting total nodes on the right side of the root
    printf("Total number of nodes on the right side of the root: %d\n", countNodesOnRight(root));

    return 0;
}
