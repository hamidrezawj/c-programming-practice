#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int key) {
    Node *newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int key) {

    // Empty position found
    if (root == NULL)
        return createNode(key);

    // Smaller -> left
    if (key < root->key)
        root->left = insert(root->left, key);

    // Bigger -> right
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {

    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 3);

    printf("In-order: ");
    inorder(root);

    printf("\n");

    return 0;
}
