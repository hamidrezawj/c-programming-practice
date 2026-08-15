#include <stdio.h>

int trace(int n, int *calls, int memo[]) {
    (*calls)++;

    if (n <= 0) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    printf("#");

    memo[n] =
        trace(n - 1, calls, memo)
        + trace(n - 2, calls, memo)
        + 1;

    return memo[n];
}

int main(void) {
    int n = 5;
    int calls = 0;

    int memo[6];

    for (int i = 0; i <= 5; i++) {
        memo[i] = -1;
    }

    int result = trace(n, &calls, memo);

    printf("\nresult = %d\n", result);
    printf("calls = %d\n", calls);

    return 0;
}
