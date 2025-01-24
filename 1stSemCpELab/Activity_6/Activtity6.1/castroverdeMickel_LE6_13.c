/*
============================================================================
FILE : LE6_13.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Power Problem Solver
Create a program that lets the user choose an operation (power problem solver,
factorial problem solver, or finding roots for quadratic equations using quadratic
formula) from the menu. The program will always go back to the menu and lets the
user choose again an operation until the user would like to quit using the app

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 10-17-24 By: Mickel Angelo Castroverde
Description: Finished the program and for the spacing, it's for my code readability
because i have a hard time reading the code if they don't have proper spacing.
============================================================================
*/

#include <stdio.h>
#include <math.h>

void displayMenu();                        // Requested function prototypes
int powerSolver(int base, int p);
int factorialSolver(int num);
int quadraticSolver(int a, int b, int c);

double root1, root2;                            // Global variables for quadratic roots

void displayMenu() {                             // Display the Menu
    printf("\nProblem Solver Menu:\n");
    printf("1. Power Problem Solver\n");
    printf("2. Factorial Problem Solver\n");
    printf("3. Quadratic Equation Solver\n");
    printf("4. Quit\n");
    printf("Enter your choice:");
}

int powerSolver(int base, int p)
{
    int result = 1;

    for (int i = 0; i < p; ++i)
    {
        result *= base;   // Multiply the base then uses the result as the new base until the power is reached
    }                     // or the loop breaks
    return result;
}

int factorialSolver(const int num)
{
    if (num < 0)
    return -1;          // Error for negative input
    int factorial = 1;

    for (int i = 1; i <= num; ++i)
    {
        factorial *= i; // Multiply the result
    }
    return factorial;
}

int quadraticSolver(int a, int b, int c)      // ax^2 + bx + c = 0
{
    const int discriminant = b * b - 4 * a * c;
    if (a == 0 && b == 0)
    {
        return -1; // No solution
    }
    if (a == 0)
    {
        root1 = -c / (double)b;
        return 1; // One root
    }
    if (discriminant < 0)
    {
        return 0; // No real roots
    }
    if (discriminant == 0)
    {
        root1 = -b / (2.0 * a);
        return 1; // One root
    }
    root1 = (-b + sqrt(discriminant)) / (2.0 * a);
    root2 = (-b - sqrt(discriminant)) / (2.0 * a);
    return 2; // Two roots
}

void userNum(int choice)
{
    int base, exponent, num, a, b, c, result;
    switch (choice)
    {
        case 1:

            printf("Enter base:");
            scanf("%d", &base);

            printf("Enter exponent:");
            scanf("%d", &exponent);

            result = powerSolver(base, exponent);
            printf("%d raised to the power of %d is %d\n", base, exponent, result);
            break;

        case 2:

            printf("Enter a positive integer: ");
            if (scanf("%d", &num) != 1 || num < 0)
            {
                printf("Invalid input. Please enter a positive integer.\n");
                while (getchar() != '\n') {}     // Clear the input buffer
                return;
            }
            result = factorialSolver(num);
            printf("Factorial of %d = %d\n", num, result);
            break;

        case 3:

            printf("Enter coefficient a: ");
            scanf("%d", &a);

            printf("Enter coefficient b: ");
            scanf("%d", &b);

            printf("Enter coefficient c: ");
            scanf("%d", &c);

            result = quadraticSolver(a, b, c);
            if (result == -1) {
                printf("There is no solution.\n");

            } else if (result == 0) {
                printf("There are no real roots.\n");

            } else if (result == 1) {
                printf("There is one root: %.2lf\n", root1);

            } else {
                printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
            }
            break;

        case 4:

            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {    // Display Menu
    int choice;

    while (1)
    {
        displayMenu();
        if (scanf("%d", &choice) != 1) {  // checks if the input is a valid input
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n') {} // Clear the input buffer
            continue;
        }
        userNum(choice);
    }
}