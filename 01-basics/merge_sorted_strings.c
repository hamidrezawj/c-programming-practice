#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Check that the string:
   1. contains only lowercase letters a-z
   2. is sorted in ascending order
*/
static int valid_sorted_lowercase(const char *s) {
    if (s == NULL) {
        return 0;
    }

    for (size_t i = 0; s[i] != '\0'; i++) {

        if (s[i] < 'a' || s[i] > 'z') {
            return 0;
        }

        if (i > 0 && s[i] < s[i - 1]) {
            return 0;
        }
    }

    return 1;
}


/* Merge two sorted lowercase strings */
char *merge_string(const char *s1, const char *s2) {

    if (!valid_sorted_lowercase(s1) ||
        !valid_sorted_lowercase(s2)) {
        return NULL;
    }

    size_t n1 = strlen(s1);
    size_t n2 = strlen(s2);

    char *out = malloc((n1 + n2 + 1) * sizeof(char));

    if (out == NULL) {
        return NULL;
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < n1 && j < n2) {

        if (s1[i] <= s2[j]) {
            out[k] = s1[i];
            i++;
        } else {
            out[k] = s2[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        out[k] = s1[i];
        i++;
        k++;
    }

    while (j < n2) {
        out[k] = s2[j];
        j++;
        k++;
    }

    out[k] = '\0';

    return out;
}


int main(void) {

    const char *s1 = "ace";
    const char *s2 = "bdf";

    char *result = merge_string(s1, s2);

    if (result == NULL) {
        printf("Invalid input or memory allocation failed.\n");
        return 1;
    }

    printf("First string:  %s\n", s1);
    printf("Second string: %s\n", s2);
    printf("Merged string: %s\n", result);

    free(result);

    return 0;
}
