#include <stdio.h>

void add();
void subtract();
void multiply();
void divide();
void modulo();

int main() {
    int choice;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulo\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                modulo();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void add() {
    int a, b;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a + b);
}
void subtract() {
    int a, b;
    printf("Enter two numbers to subtract: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a - b);
}
void multiply() {
    int a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a * b);
}
void divide() {
    int a, b;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %f\n", (float)a / b);
    }
}
void modulo() {
    int a, b;
    printf("Enter two numbers to find modulo: ");
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Error: Modulo by zero is not allowed.\n");
    } else {
        printf("Result: %d\n", a % b);
    }
}
