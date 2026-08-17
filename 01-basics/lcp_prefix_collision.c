#include <stdio.h>
#include <string.h>


/* Find and print the longest common prefix */
void lcp(const char *strings[], int n) {

    if (strings == NULL || n <= 0) {
        printf("LCP: empty\n");
        return;
    }

    size_t limit = strlen(strings[0]);

    for (int i = 1; i < n; i++) {

        size_t j = 0;

        while (j < limit &&
               strings[i][j] != '\0' &&
               strings[i][j] == strings[0][j]) {

            j++;
        }

        limit = j;
    }

    printf("LCP: ");

    for (size_t i = 0; i < limit; i++) {
        printf("%c", strings[0][i]);
    }

    printf("\n");
}


/* Find cases where the shorter string is
   a prefix of the longer string */
void detect_prefix_collisions(const char *strings[], int n) {

    int found = 0;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            size_t len1 = strlen(strings[i]);
            size_t len2 = strlen(strings[j]);

            /* Equal-length strings are not considered collisions */
            if (len1 == len2) {
                continue;
            }

            const char *shorter;
            const char *longer;
            size_t short_len;

            if (len1 < len2) {
                shorter = strings[i];
                longer = strings[j];
                short_len = len1;
            } else {
                shorter = strings[j];
                longer = strings[i];
                short_len = len2;
            }

            if (strncmp(shorter, longer, short_len) == 0) {

                printf("Prefix collision: \"%s\" -> \"%s\"\n",
                       shorter, longer);

                found = 1;
            }
        }
    }

    if (!found) {
        printf("No prefix collisions found.\n");
    }
}


int main(void) {

    const char *strings[] = {
        "flower",
        "flow",
        "flight"
    };

    int n = sizeof(strings) / sizeof(strings[0]);

    lcp(strings, n);

    detect_prefix_collisions(strings, n);

    return 0;
}
