#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int size;

    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int key) {

    Node *newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->size = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getSize(Node *root) {
    if (root == NULL)
        return 0;

    return root->size;
}

Node *insert(Node *root, int key) {

    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    // Update size after insertion
    root->size =
        1 +
        getSize(root->left) +
        getSize(root->right);

    return root;
}

void inorder(Node *root) {

    if (root == NULL)
        return;

    inorder(root->left);

    printf("key = %d, size = %d\n",
           root->key,
           root->size);

    inorder(root->right);
}

int main() {

    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    inorder(root);

    return 0;
}
