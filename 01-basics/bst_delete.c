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

    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Find smallest node in right subtree
Node *findMin(Node *root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *deleteNode(Node *root, int key) {

    if (root == NULL)
        return NULL;

    // Search for node
    if (key < root->key) {

        root->left =
            deleteNode(root->left, key);

    } else if (key > root->key) {

        root->right =
            deleteNode(root->right, key);

    } else {

        // Case 1: no left child
        if (root->left == NULL) {

            Node *temp = root->right;
            free(root);

            return temp;
        }

        // Case 2: no right child
        if (root->right == NULL) {

            Node *temp = root->left;
            free(root);

            return temp;
        }

        // Case 3: two children

        Node *successor =
            findMin(root->right);

        root->key = successor->key;

        root->right =
            deleteNode(
                root->right,
                successor->key
            );
    }

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
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    printf("Before deletion:\n");
    inorder(root);

    root = deleteNode(root, 10);

    printf("\nAfter deleting 10:\n");
    inorder(root);

    printf("\n");

    return 0;
}
