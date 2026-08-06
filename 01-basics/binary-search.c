#include <stdio.h>

int binary_search(int v[], int l, int r, int key)
{
    if (l > r)
        return -1;

    int m = l + (r - l) / 2;

    if (v[m] == key)
        return m;

    if (key < v[m])
        return binary_search(v, l, m - 1, key);

    return binary_search(v, m + 1, r, key);
}

int main(void)
{
    int v[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(v) / sizeof(v[0]);
    int key = 11;

    int result = binary_search(v, 0, n - 1, key);

    if (result == -1)
        printf("Number not found.\n");
    else
        printf("Number found at index %d.\n", result);

    return 0;
}
