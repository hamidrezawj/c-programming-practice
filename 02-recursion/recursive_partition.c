#include <stdio.h>

void show(int v[], int l, int r)
{
    int c;

    printf("Range: %d to %d\n", l, r);

    if (l >= r) {
        printf("  Element: %d\n", v[l]);
        return;
    }

    c = (l + r) / 2;

    show(v, l, c);
    show(v, c + 1, r);
}

int main(void)
{
    int v[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(v) / sizeof(v[0]);

    show(v, 0, n - 1);

    return 0;
}
