#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Prefix = Pre-order
void prefix(Node *root) {
    if (root == NULL)
        return;

    printf("%c ", root->value);
    prefix(root->left);
    prefix(root->right);
}

// Postfix = Post-order
void postfix(Node *root) {
    if (root == NULL)
        return;

    postfix(root->left);
    postfix(root->right);
    printf("%c ", root->value);
}

int main() {

    /*
            *
           / \
          +   C
         / \
        A   B
    */

    Node *root = createNode('*');

    root->left = createNode('+');
    root->right = createNode('C');

    root->left->left = createNode('A');
    root->left->right = createNode('B');

    printf("Prefix: ");
    prefix(root);

    printf("\nPostfix: ");
    postfix(root);

    printf("\n");

    return 0;
}
