/*
============================================================================
FILE : LE7_11.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Largest and Smallest
Design a logic for a program that allows user to enter 10 numbers, then displays
all of the numbers, the largest number, and the smallest.

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

void inputNum(int num[10]);     // function for inputting the numbers
void logicLoop (int num[10]);  // function for processing the largest and smallest number
void printNum (int num[10]);  // function for printing the numbers

int main()
{
    int num[10];        // array to store 10 integers

    inputNum(num);    // call function to input numbers
    printNum(num);    // call function to print numbers
    logicLoop(num);   // call function to process numbers
    
    return 0; 
}

/*
============================================================================
 FUNCTION    : inputNum
 DESCRIPTION : Inputs 10 numbers from the user
 ARGUMENTS   : int num[10] - array to store the inputted numbers
 RETURNS     : void
===========================================================================
*/

void inputNum(int num[10])                      // function to input 10 numbers from the user
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1); // prompt user to enter a number
        while (scanf("%d", &num[i]) != 1)  // verify if the input is an integer 
        {
            printf("Invalid input. Please enter an integer: ");               // i really liked this function because it clears the buffer
            while (getchar() != '\n'); // clear the input buffer             // to avoid messing with other inputs
            
        }
    }
}

/*
============================================================================
 FUNCTION    : logicLoop
 DESCRIPTION : Processes the largest and smallest number
 ARGUMENTS   : int num[10] - array of inputted numbers
 RETURNS     : void
===========================================================================
*/
void logicLoop (int num[10]) // function for processing the largest and smallest number
{
    int largeNum;          // variable to store the largest number
    int smallNum;         // variable to store the smallest number

    largeNum = smallNum = num[0];

    for (int i = 1; i < 10; i++)
    {
        if (num[i] > largeNum)
        {
            largeNum = num[i];
        }
        if (num[i] < smallNum)
        {
            smallNum = num[i];
        }
    }

    printf("Largest number: %d\n", largeNum); // printing the largest and smallest number
    printf("Smallest number: %d\n", smallNum);
}

/*
============================================================================
 FUNCTION    : printNum
 DESCRIPTION : Prints the numbers
 ARGUMENTS   : int num[10] - array of inputted numbers
 RETURNS     : void
===========================================================================
*/

void printNum (int num[10])               // function for printing the numbers
{
    printf("The numbers are: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", num[i]);
    }
    printf("\n");
}
