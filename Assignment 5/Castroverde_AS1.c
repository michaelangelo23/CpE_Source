/*
============================================================================
FILE : Castroverde_AS1.c
AUTHOR : Mickel Angelo Castroverde
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
DESCRIPTION : A program that performs various calculations including the area and volume of a cylinder,
              balance calculation for an account, and final velocity and travel time of an object.
REVISION HISTORY
Date:09/19/24 By:Mickel Angelo Castroverde Description: finished the project
============================================================================
*/

#include <stdio.h>
#include <math.h>

// constants
#define PI 3.14159265358979323846  // value of pi
#define GRAVITY 32.1               // value of gravity

// function declaration for calculating the balance
double calculateBalance(double amount, int period, double interestRate) {
    return amount * pow((1 + interestRate / 100), period);
}

int main() {
    int choice;  // user's choice
    double radius, height, area, volume;  //  variables for cylinder calculations
    double amount, interestRate, accountBalance;  // variables for balance calculations
    double initialVelocity, finalVelocity, travelTime;  // variables for velocity and time calculations
    int period;  // variable for the period in years

    // display menu options
    printf("Choose what program you wish to solve:\n");
    printf("Press 1, for Cylinder\n");
    printf("Press 2, for Balance account\n");
    printf("Press 3, for Final velocity and Travel time\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // is the user input is "1"
    if (choice == 1) {
        // prompts and gets height and radius from the user
        printf("Enter the radius of the cylinder: ");
        scanf("%lf", &radius);
        printf("Enter the height of the cylinder: ");
        scanf("%lf", &height);

        // calculation for surface area and volume of the cylinder
        area = (2 * PI * radius * height) + (2 * PI * radius * radius);
        volume = PI * radius * radius * height;

        // display the results
        printf("Area of cylinder is: %.2lf\n", area);
        printf("Volume of cylinder is: %.2lf\n", volume);
    }
    else if (choice == 2) { // if the user's input is "2"
        // prompts and gets the amount, period, and interest rate from the user
        printf("Enter the amount: ");
        scanf("%lf", &amount);
        printf("Enter the period (in years): ");
        scanf("%d", &period);
        printf("Enter the interest rate (in percentage): ");
        scanf("%lf", &interestRate);

        // calculate the account balance
        accountBalance = calculateBalance(amount, period, interestRate);

        // display the result
        printf("Balance calculation is: %.2lf\n", accountBalance);
    }
    else if (choice == 3) { // if the user's input is "3"
        // prompts and gets the height and initial velocity from the user
        printf("Enter the height of the tower: ");
        scanf("%lf", &height);
        printf("Enter the initial velocity: ");
        scanf("%lf", &initialVelocity);

        // calculate the final velocity and travel time
        finalVelocity = sqrt(initialVelocity * initialVelocity + 2 * GRAVITY * height);
        travelTime = (finalVelocity - initialVelocity) / GRAVITY;

        // display the results
        printf("Final velocity is: %.2lf\n", finalVelocity);
        printf("Travel time is: %.2lf\n", travelTime);
    }
    else {
        // throw and error if outside the selection
        printf("Error: Invalid choice. Please select a valid option.\n");
    }

    return 0;
}