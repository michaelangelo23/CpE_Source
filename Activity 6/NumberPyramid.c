/*
============================================================================
FILE : LE5_22.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : This program will print a number pyramid based on the value of N
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 10-02-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

int main()
{
    int num, i, j, k, l;
    printf("Enter a value for N: ");
    scanf("%d", &num);
    // Asks for a value for N
    for (i = 1; i <= num; i++) // Loop for rows
    {
        for (j = 1; j <= num - i; j++) // Prints spaces
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++) // Prints numbers in ascending order
        {  
            printf("%d", k);
        }
        for (l = i - 1; l >= 1; l--) // Prints numbers in descending order
        {
            printf("%d", l);
        }
        printf("\n"); // New line
    }
    return 0;
}