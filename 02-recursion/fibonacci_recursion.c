#include <stdio.h>

// Calculate Fibonacci number using recursion
int fibonacci(int n)
{
    // Base case
    if (n <= 1)
    {
        return n;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int n = 10;

    printf("Fibonacci sequence:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}

