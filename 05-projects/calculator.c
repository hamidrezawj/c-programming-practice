#include <stdio.h>

int main(void) {
    double first_number;
    double second_number;
    double result;
    char operation;

    printf("Enter the first number: ");

    if (scanf("%lf", &first_number) != 1) {
        printf("Invalid number.\n");
        return 1;
    }

    printf("Choose an operation (+, -, *, /): ");

    if (scanf(" %c", &operation) != 1) {
        printf("Invalid operation.\n");
        return 1;
    }

    printf("Enter the second number: ");

    if (scanf("%lf", &second_number) != 1) {
        printf("Invalid number.\n");
        return 1;
    }

    switch (operation) {
        case '+':
            result = first_number + second_number;
            break;

        case '-':
            result = first_number - second_number;
            break;

        case '*':
            result = first_number * second_number;
            break;

        case '/':
            if (second_number == 0) {
                printf("Division by zero is not allowed.\n");
                return 1;
            }

            result = first_number / second_number;
            break;

        default:
            printf("Invalid operation.\n");
            return 1;
    }

    printf("Result: %.2f\n", result);

    return 0;
}
