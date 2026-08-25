#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
 * Finds all local maximum cells.
 *
 * k = radius of neighborhood
 */
void local_max(int **m, int n, int k)
{
    for (int r = 0; r < n; r++) {

        for (int c = 0; c < n; c++) {

            int is_max = 1;

            for (int i = r - k; i <= r + k && is_max; i++) {

                for (int j = c - k; j <= c + k; j++) {

                    // Ignore cells outside matrix
                    if (i < 0 || j < 0 || i >= n || j >= n)
                        continue;


                    if (m[i][j] > m[r][c]) {
                        is_max = 0;
                        break;
                    }
                }
            }


            if (is_max) {
                printf("Local max: %d at [%d][%d]\n",
                       m[r][c], r, c);
            }
        }
    }
}


/*
 * Finds k x k square with maximum sum.
 *
 * k = size of square
 */
void max_k_square(int **m, int n, int k)
{
    int best = INT_MIN;
    int best_r = -1;
    int best_c = -1;


    for (int r = 0; r + k <= n; r++) {

        for (int c = 0; c + k <= n; c++) {

            int sum = 0;


            for (int i = r; i < r + k; i++) {

                for (int j = c; j < c + k; j++) {

                    sum += m[i][j];
                }
            }


            if (sum > best) {

                best = sum;
                best_r = r;
                best_c = c;
            }
        }
    }


    printf("Best square sum = %d, top-left = [%d][%d]\n",
           best, best_r, best_c);
}



int main(void)
{
    int n = 4;


    int **matrix = malloc(n * sizeof(*matrix));


    if (matrix == NULL)
        return 1;


    for (int i = 0; i < n; i++) {

        matrix[i] = malloc(n * sizeof(**matrix));


        if (matrix[i] == NULL)
            return 1;
    }



    int values[4][4] = {
        {1, 2, 3, 4},
        {5, 9, 7, 8},
        {2, 6, 10, 1},
        {4, 3, 2, 0}
    };



    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            matrix[i][j] = values[i][j];
        }
    }



    printf("Matrix:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }



    printf("\nLocal maximums:\n");

    local_max(matrix, n, 1);



    printf("\nMaximum k-square:\n");

    max_k_square(matrix, n, 2);



    for (int i = 0; i < n; i++) {

        free(matrix[i]);
    }

    free(matrix);


    return 0;
}
