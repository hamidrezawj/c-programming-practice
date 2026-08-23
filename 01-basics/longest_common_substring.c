#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Finds the longest common contiguous substring
 * between two strings.
 *
 * The function prints the substring and returns its length.
 * Returns -1 if memory allocation fails.
 */
int common_substring(const char *a, const char *b)
{
    int n = (int)strlen(a);
    int m = (int)strlen(b);

    /*
     * dp[i][j] stores the length of the common substring
     * ending at a[i - 1] and b[j - 1].
     */
    int **dp = malloc((n + 1) * sizeof(*dp));

    if (dp == NULL) {
        return -1;
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(m + 1, sizeof(**dp));

        if (dp[i] == NULL) {

            /* Free previously allocated rows */
            for (int k = 0; k < i; k++) {
                free(dp[k]);
            }

            free(dp);
            return -1;
        }
    }

    int best = 0;
    int end = 0;

    /*
     * Compare every character of string a
     * with every character of string b.
     */
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > best) {
                    best = dp[i][j];
                    end = i;
                }

            } else {
                dp[i][j] = 0;
            }
        }
    }

    printf("Longest common substring: ");

    if (best > 0) {
        printf("%.*s", best, a + end - best);
    } else {
        printf("None");
    }

    printf("\n");

    /* Free the allocated 2D array */
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }

    free(dp);

    return best;
}


int main(void)
{
    const char *str1 = "xxabczz";
    const char *str2 = "yyabcww";

    int length = common_substring(str1, str2);

    if (length == -1) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Length: %d\n", length);

    return 0;
}
