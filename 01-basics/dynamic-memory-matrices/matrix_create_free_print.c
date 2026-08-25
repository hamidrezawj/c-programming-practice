#include <stdio.h>
#include <stdlib.h>

/*
 * Creates a dynamic matrix using int **.
 * Each row is allocated separately with calloc.
 */
int **matrix_create(int rows, int cols)
{
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    int **matrix = malloc(rows * sizeof(*matrix));

    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {

        matrix[i] = calloc(cols, sizeof(*matrix[i]));

        if (matrix[i] == NULL) {

            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }

            free(matrix);

            return NULL;
        }
    }

    return matrix;
}


void matrix_free(int **matrix, int rows)
{
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
}


void matrix_print(int **matrix, int rows, int cols)
{
    if (matrix == NULL) {
        return;
    }

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}


int main(void)
{
    int rows = 3;
    int cols = 4;

    int **matrix = matrix_create(rows, cols);

    if (matrix == NULL) {
        printf("Matrix allocation failed\n");
        return 1;
    }


    int value = 1;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            matrix[i][j] = value;
            value++;
        }
    }


    printf("Matrix:\n");

    matrix_print(matrix, rows, cols);


    matrix_free(matrix, rows);

    return 0;
}
