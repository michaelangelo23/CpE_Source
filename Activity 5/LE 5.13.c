#include <stdio.h>
#include <math.h>

// variables declared in the global scope kay dili man pwede inside the function
int choice;
double base, result, a, b, c, root1, root2, discriminant;
int exponent, n, i;
unsigned long long factorial;

int clearInputBuffer() {
    while (getchar() != '\n') {} // clear invalid input
    return 0;
}

int main() {
    do {
        // display menu
        printf("\nProblem Solver Menu:\n");
        printf("1. Power Problem Solver\n");
        printf("2. Factorial Problem Solver\n");
        printf("3. Quadratic Equation Solver\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer(); // clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 1) {
            // power problem solver
            printf("Enter base: ");
            while (scanf("%lf", &base) != 1) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter a number for base: ");
            }

            printf("Enter exponent: ");
            while (scanf("%d", &exponent) != 1) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter an integer for exponent: ");
            }

            result = pow(base, exponent);
            printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);

        } else if (choice == 2) {
            // factorial problem solver
            factorial = 1;

            printf("Enter a positive integer: ");
            while (scanf("%d", &n) != 1 || n < 0) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter a positive integer: ");
            }

            for (i = 1; i <= n; ++i) {
                factorial *= i;
            }
            printf("Factorial of %d = %llu\n", n, factorial);

        } else if (choice == 3) {
            // quadratic equation solver
            printf("Enter coefficient a: ");
            while (scanf("%lf", &a) != 1) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter a number for coefficient a: ");
            }

            printf("Enter coefficient b: ");
            while (scanf("%lf", &b) != 1) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter a number for coefficient b: ");
            }

            printf("Enter coefficient c: ");
            while (scanf("%lf", &c) != 1) {
                clearInputBuffer(); // clear invalid input
                printf("Invalid input. Please enter a number for coefficient c: ");
            }

            if (a == 0 && b == 0) {
                printf("There is no solution.\n");
            } else if (a == 0) {
                root1 = -c / b;
                printf("There is one root: %.2lf\n", root1);
            } else {
                discriminant = b * b - 4 * a * c;

                if (discriminant < 0) {
                    printf("There are no real roots.\n");
                } else if (discriminant == 0) {
                    root1 = -b / (2 * a);
                    printf("There is one root: %.2lf\n", root1);
                } else {
                    root1 = (-b + sqrt(discriminant)) / (2 * a);
                    root2 = (-b - sqrt(discriminant)) / (2 * a);
                    printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
                }
            }

        } else if (choice == 4) {
            printf("Exiting the program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
