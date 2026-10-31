#include <stdio.h>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

int main(void) {
    double first, second;
    char op, again;

    do {
        printf("\n=== SIMPLE C CALCULATOR ===\n");
        printf("Enter an expression (example: 12 + 5): ");

        if (scanf("%lf %c %lf", &first, &op, &second) != 3) {
            printf("Invalid input. Please enter two numbers and an operator.\n");
            return 1;
        }

        switch (op) {
            case '+':
                printf("Result: %.2f\n", add(first, second));
                break;
            case '-':
                printf("Result: %.2f\n", subtract(first, second));
                break;
            case '*':
                printf("Result: %.2f\n", multiply(first, second));
                break;
            case '/':
                if (second == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2f\n", first / second);
                }
                break;
            default:
                printf("Invalid operator. Use +, -, * or /.\n");
        }

        printf("Calculate again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}
