/*
============================================================================
FILE : fileName.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : projectDescription
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 10-03-24 By: Mickel Angelo Castroverde Description: finished and refactored the project
============================================================================
*/
#include <stdio.h>

int main() {

    int limit, i, j, k;
    // Prompt for the limit
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Check if the limit exceeds 9
    if (limit > 9) {
        printf("Limit Exceeded\n");
        return 1; // Exit the program if the limit is exceeded
    }

    // Code for Number 1
    for (i = 1; i <= limit; i++) {
        for (j = 1; j < i; j++) {
            printf("*");
        }
        printf("%d\n", i);
    }

    // Code for Number 2
    for (i = 1; i <= limit; i++) {
        for (j = limit; j > i; j--) {
            printf(" ");
        }
        for (k = 1; k < i; k++) {
            printf("*");
        }
        printf("%d", i);
        for (k = 1; k < i; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Code for Number 3
    for (int i = 1; i <= 9; i++) {
        // Print leading spaces
        for (int j = 9; j > i; j--) {
            printf(" ");
        }
        // Print the number
        printf("%d", i);
        // Print asterisks
        for (int k = 1; k < i; k++) {
            printf("*");
        }
        // New line after each row
        printf("\n");
    }

    // Code for Number 4
    for (i = 1; i <= limit; i++) {
        for (j = 1; j < i; j++) {
            printf("*");
        }
        printf("%d", i);
        for (k = 1; k <= (limit - i) * 2; k++) {
            printf(" ");
        }
        printf("%d", i);
        for (j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    // Code for number 5
    for (i = 1; i <= limit; i++) {
        for (j = 1; j <= limit - i; j++) {
            printf("*");
        }
        printf("%d", i);
        if (i != limit) {
            for (j = 1; j <= 2 * (i - 1); j++) {
                printf(" ");
            }
            printf("%d", i);
        } else {
            for (j = 1; j <= 2 * (i - 1); j++) {
                printf(" ");
            }
            printf("%d", i);
        }
        for (j = 1; j <= limit - i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}