#include <stdio.h>
#include <math.h>
#include <limits.h>

void power_problem_solver() {
    double base, result;
    int exponent;
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    result = pow(base, exponent);
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);
}

void factorial_problem_solver() {
    int n;
    unsigned long long factorial = 1;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        while (getchar() != '\n'); // Clear the input buffer
        return;
    }
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    printf("Factorial of %d = %llu\n", n, factorial);
}

void quadratic_equation_solver() {
    double a, b, c, root1, root2, discriminant;
    printf("Enter coefficient a: ");
    scanf("%lf", &a);
    printf("Enter coefficient b: ");
    scanf("%lf", &b);
    printf("Enter coefficient c: ");
    scanf("%lf", &c);

    discriminant = b * b - 4 * a * c;
    const double epsilon = 1e-7;
    if (fabs(a) < epsilon && fabs(b) < epsilon) {
        printf("There is no solution.\n");
    } else if (fabs(a) < epsilon) {
        root1 = -c / b;
        printf("There is one root: %.2lf\n", root1);
    } else if (discriminant < 0) {
        printf("There are no real roots.\n");
    } else if (fabs(discriminant) < epsilon) {
        root1 = -b / (2 * a);
        printf("There is one root: %.2lf\n", root1);
    } else {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
    }
}

void display_menu() {
    printf("\nProblem Solver Menu:\n");
    printf("1. Power Problem Solver\n");
    printf("2. Factorial Problem Solver\n");
    printf("3. Quadratic Equation Solver\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void handle_choice(int choice) {
    switch (choice) {
        case 1:
            power_problem_solver();
            break;
        case 2:
            factorial_problem_solver();
            break;
        case 3:
            quadratic_equation_solver();
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice;

    // Display Menu
    while (1) {
        display_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        handle_choice(choice);
    }

    return 0;
}