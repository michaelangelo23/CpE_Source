/*
============================================================================
FILE : comLabPractice.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Array with Modularization
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-05-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

void inputNum(int num[5][6]);   // Forgot to put this, mark the warning as resolve
void printTable(int num[5][6]); // warnings were present due to this declaration not present before

int main()
{
    int num[5][6]; // Declare a 5x6 array
    inputNum(num); // Call function to input values into the array
    printTable(num); // Call function to print the array
    return 0;
}

void inputNum(int num[5][6]) // Function to input values into the array
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            printf("Enter number (%d)(%d): ", row + 1, col + 1);
            scanf("%d", &num[row][col]);
        }
    }
}
void printTable(int num[5][6]) // Function to print the array in table format
{
    printf("The entered numbers are:\n");
    for (int row = 0; row < 5; row++) // printing for each row
    {
        for (int col = 0; col < 6; col++) // printing for each column
        {
            printf("%d ", num[row][col]);
        }
        printf("\n");
    }
}


/* WARNINGS FROM CODE

||=== Build file: "no target" in "no project" (compiler: unknown) ===|
Z:\Pointers.c||In function 'main':|
Z:\Pointers.c|18|warning: implicit declaration of function 'inputNum' [-Wimplicit-function-declaration]|
Z:\Pointers.c|19|warning: implicit declaration of function 'printTable'; did you mean '_printf_l'? [-Wimplicit-function-declaration]|
Z:\Pointers.c|23|warning: conflicting types for 'inputNum'|
Z:\Pointers.c|18|note: previous implicit declaration of 'inputNum' was here|
Z:\Pointers.c|34|warning: conflicting types for 'printTable'|
Z:\Pointers.c|19|note: previous implicit declaration of 'printTable' was here|
||=== Build finished: 0 error(s), 4 warning(s) (0 minute(s), 0 second(s)) ===|


*/
