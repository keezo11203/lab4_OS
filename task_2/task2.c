#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

/* Function pointers */
int (*operations[4])(int, int) = {add, subtract, multiply, divide};

/* Function definitions */
int add(int a, int b) {
    printf("Adding %d and %d\n", a, b);
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting %d from %d\n", b, a);
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying %d and %d\n", a, b);
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        printf("Dividing %d by %d\n", a, b);
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0; // Return some default value, as division by zero is undefined
    }
}

int main(void) {
    char operation;
    int operand1 = 10;
    int operand2 = 5;

    printf("Enter operation (0: add, 1: subtract, 2: multiply, 3: divide, 4: exit): ");
    scanf(" %c", &operation);

    int result = operations[operation - '0'](operand1, operand2);

    printf("Result: %d\n", result);

    return 0;
}
