#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the sum of all node values in BST
int sumNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively sum nodes in left and right subtrees
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int values[] = {10, 5, 15, 3, 7, 12, 18};

    // Insert values into BST
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    // Calculate the sum of all node values
    int totalSum = sumNodes(root);

    printf("Sum of all node values in the BST: %d\n", totalSum);

    return 0;
}
