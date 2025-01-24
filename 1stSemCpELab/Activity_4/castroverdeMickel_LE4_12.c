/*
============================================================================
FILE : LE4_12.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Solves a quadratic equation of the form ax^2 + bx + c = 0
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-05-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;

    // Prompt user for input
    printf("Enter the coefficient a: ");
    if (scanf("%lf", &a) != 1) {
        // Check if input is valid
        printf("Invalid  input.\n");
        return 1;
    }

    printf("Enter the coefficient b: ");
    if (scanf("%lf", &b) != 1) {
        // Check if input is valid
        printf("Invalid input.\n");
        return 2;
    }

    printf("Enter the coefficient c: ");
    if (scanf("%lf", &c) != 1) {
        // Check if input is valid
        printf("Invalid input.\n");
        return 3;
    }

    // Check for degenerate case
    if (a == 0 && b == 0) {
        printf("No solution.\n");
        return 0;
    }

    // Determine equation type and solve
    if (a == 0) {
        double root = -c / b;
        printf("One root: %.2f\n", root);
    } else {
        // Calculate the discriminant
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            // No real roots if discriminant is negative
            printf("No roots.\n");
        } else if (discriminant  == 0) {
            // One real root if discriminant nt is zero
            double root = -b / (2 *  a);
            printf("One root: %.2f\n", root);
        } else {
            // Two real roots if discriminant is positive
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("Two roots:\n");
            printf("Root 1: %.2f\n", root1);
            printf("Root 2: %.2f\n", root2);
        }
    }

    return 0;
}
