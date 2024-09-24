// same with LE 5.13.c but removed the error checking (clearInputBuffer)
#include <stdio.h>
#include <math.h>

int main() { // variable declarations in the global scope
    int choice;
    double base, result, a, b, c, root1, root2, discriminant;
    int exponent, n;
    unsigned long long factorial;

    while (1) { //display menu
        printf("\nProblem Solver Menu:\n");
        printf("1. Power Problem Solver\n");
        printf("2. Factorial Problem Solver\n");
        printf("3. Quadratic Equation Solver\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) { // error for invalid option
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 1) {
            // power problem solver 
            printf("Enter base: ");
            scanf("%lf", &base); 
            printf("Enter exponent: ");
            scanf("%d", &exponent);
            result = pow(base, exponent);
            printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);

        } else if (choice == 2) {
            //factorial problem solver
            factorial = 1;
            printf("Enter a positive integer: ");
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) { // if i is less than or equal to n, multiply the factorial by i
                factorial *= i;
            }
            printf("Factorial of %d = %llu\n", n, factorial); //display the result

        } else if (choice == 3) {
            //quadratic equation solver
            printf("Enter coefficient a: ");  // input the asked coefficients
            scanf("%lf", &a);
            printf("Enter coefficient b: ");
            scanf("%lf", &b);
            printf("Enter coefficient c: ");
            scanf("%lf", &c);

            discriminant = b * b - 4 * a * c; // calculate the discriminant
            if (a == 0 && b == 0) {
                printf("There is no solution.\n");
            } else if (a == 0) {
                root1 = -c / b; 
                printf("There is one root: %.2lf\n", root1); //display the result
            } else if (discriminant < 0) {
                printf("There are no real roots.\n"); //display the result
            } else if (discriminant == 0) {
                root1 = -b / (2 * a); 
                printf("There is one root: %.2lf\n", root1);
            } else {                                           // if the discriminant is greater than 0
                root1 = (-b + sqrt(discriminant)) / (2 * a);
                root2 = (-b - sqrt(discriminant)) / (2 * a);
                printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
            }

        } else if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
