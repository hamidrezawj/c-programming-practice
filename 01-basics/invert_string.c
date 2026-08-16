#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int invert_string(const char *s1, char **s2) {
    size_t n;

    if (s1 == NULL || s2 == NULL) {
        return 0;
    }

    n = strlen(s1);

    *s2 = malloc((n + 1) * sizeof(char));

    if (*s2 == NULL) {
        return 0;
    }

    for (size_t i = 0; i < n; i++) {
        (*s2)[i] = s1[n - 1 - i];
    }

    (*s2)[n] = '\0';

    return 1;
}

int main(void) {
    char *out = NULL;

    if (invert_string("ALGORITHM", &out)) {
        printf("%s\n", out);
        free(out);
    }

    return 0;
}
