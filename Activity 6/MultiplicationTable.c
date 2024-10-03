/*
============================================================================
FILE : LE5_21.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Prints a multiplication table using nested loops
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 10-01-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

int main()
{
    int row, col, j;

    // Prompt the user to enter the number of rows
    printf("Enter number of rows: ");
    scanf("%d", &row);

    // Prompt the user to enter the number of columns
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Print the column headers
    printf("     ");
    for (j = 1; j <= col; j++) {
        printf("%4d", j);
    }
    printf("\n");

    // Print the separator line
    printf("_____");
    for (j = 1; j <= col; j++) {
        printf("____");
    }
    printf("\n");

    // Print the multiplication table
    for (int i = 1; i <= row; i++) {
        // Print the row header
        printf("%2d  |", i);
        for (j = 1; j <= col; j++) {
            // Print the product of the current row and column
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}