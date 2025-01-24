/*
============================================================================
FILE : LE5_23.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : This program will print the Fibonacci sequence up to N
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 10-02-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

int main()
{
    int limit, i, nextTerm = 1, firstTerm = 0, secondTerm = 1; // Declares variables

    printf("Enter limit: "); // Asks for a limit
    scanf("%d", &limit);

    printf("Fibonacci sequence: "); // Prints the Fibonacci sequence
    for (i = 1; i <= limit; i++){
        printf("%d ", nextTerm);
        nextTerm = firstTerm + secondTerm; // Calculates the next term
        firstTerm = secondTerm;       // Updates the first term
        secondTerm = nextTerm;      // Updates the second term
    }

    return 0;
}