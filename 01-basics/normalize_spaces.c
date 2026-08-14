#include <stdio.h>

void normalize_spaces(char *s) {
    int read = 0, write = 0;
    int previous_was_space = 1;

    while (s[read] != '\0') {
        if (s[read] != ' ') {
            s[write++] = s[read];
            previous_was_space = 0;
        } else if (!previous_was_space) {
            s[write++] = ' ';
            previous_was_space = 1;
        }

        read++;
    }

    if (write > 0 && s[write - 1] == ' ') {
        write--;
    }

    s[write] = '\0';
}

int main(void) {
    char s[] = "  this   is C  ";

    normalize_spaces(s);

    printf("%s\n", s);

    return 0;
}
