#include <stdio.h>

int main(void) {
    int number;
    int choice;
    int i;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* if, else if, else */
    if (number > 0) {
        printf("The number is positive.\n");
    } else if (number < 0) {
        printf("The number is negative.\n");
    } else {
        printf("The number is zero.\n");
    }

    /* Even or odd */
    if (number % 2 == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }

    /* for loop */
    printf("\nNumbers from 1 to 5 using for:\n");

    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }

    printf("\n");

    /* while loop */
    i = 5;

    printf("\nNumbers from 5 to 1 using while:\n");

    while (i >= 1) {
        printf("%d ", i);
        i--;
    }

    printf("\n");

    /* do-while loop */
    i = 1;

    printf("\nNumbers from 1 to 3 using do-while:\n");

    do {
        printf("%d ", i);
        i++;
    } while (i <= 3);

    printf("\n");

    /* switch */
    printf("\nChoose an option:\n");
    printf("1. Say hello\n");
    printf("2. Say goodbye\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Hello!\n");
            break;

        case 2:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
