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

Node *sortedArrayToBST(
    int array[],
    int start,
    int end
) {

    if (start > end)
        return NULL;

    int middle = (start + end) / 2;

    Node *root =
        createNode(array[middle]);

    root->left =
        sortedArrayToBST(
            array,
            start,
            middle - 1
        );

    root->right =
        sortedArrayToBST(
            array,
            middle + 1,
            end
        );

    return root;
}

void preorder(Node *root) {

    if (root == NULL)
        return;

    printf("%d ", root->key);

    preorder(root->left);
    preorder(root->right);
}

int main() {

    int array[] = {
        1, 2, 3, 4, 5, 6, 7
    };

    int n =
        sizeof(array) / sizeof(array[0]);

    Node *root =
        sortedArrayToBST(
            array,
            0,
            n - 1
        );

    printf("Pre-order of Balanced BST:\n");

    preorder(root);

    printf("\n");

    return 0;
}
