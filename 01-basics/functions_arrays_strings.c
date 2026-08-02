#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 5
#define NAME_SIZE 50

int add(int first_number, int second_number) {
    return first_number + second_number;
}

int find_maximum(const int numbers[], int size) {
    int maximum = numbers[0];
    int i;

    for (i = 1; i < size; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

void print_array(const int numbers[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}

int main(void) {
    int numbers[ARRAY_SIZE] = {12, 7, 25, 3, 18};
    int first_number = 10;
    int second_number = 20;
    int result;
    int value = 50;
    int *pointer = &value;
    char name[NAME_SIZE];

    /* Functions */
    result = add(first_number, second_number);

    printf("Function result: %d\n", result);

    /* Arrays */
    printf("\nArray values:\n");
    print_array(numbers, ARRAY_SIZE);

    printf("Maximum value: %d\n",
           find_maximum(numbers, ARRAY_SIZE));

    /* Strings */
    printf("\nEnter your name: ");

    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Could not read the name.\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);
    printf("Your name has %zu characters.\n", strlen(name));

    /* Basic pointer */
    printf("\nOriginal value: %d\n", value);
    printf("Value through pointer: %d\n", *pointer);

    *pointer = 100;

    printf("Changed value: %d\n", value);

    return 0;
}
