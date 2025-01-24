/*
============================================================================
FILE : LE7_13.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :

                            Longest String
        Ask for 5 strings and determine which string is the longest.

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/
#include <stdio.h>
#include <string.h>

void inputString(char strArray[5][100]);    // function for inputting strings
int findLongString(char strArray[5][100]); // function for finding the longest string

int main()
{
    char strArray[5][100];            // array to store 5 strings, each with a maximum length of 100 characters

    inputString(strArray);          // call function to input strings
    int longStringIndex = findLongString(strArray);                         // call function to find the longest string and store the index
    
    printf("The longest string is: %s\n", strArray[longStringIndex]);     // Print the longest string

    return 0;
}

/*
============================================================================
 FUNCTION    : inputString
 DESCRIPTION : Inputs 5 strings from the user
 ARGUMENTS   : char strArray[5][100] - array to store the inputted strings
 RETURNS     : void
===========================================================================
*/
void inputString(char strArray[5][100])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter string %d: ", i + 1);  // prompt user to enter a string
        scanf("%s", strArray[i]);           // read the string and store it in the array
    }
}

/*
============================================================================
 FUNCTION    : findLongString
 DESCRIPTION : Finds the longest string in the array
 ARGUMENTS   : char strArray[5][100] - array of inputted strings
 RETURNS     : int - index of the longest string
===========================================================================
*/
int findLongString(char strArray[5][100])
{
    int maxLength = 0;
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strlen(strArray[i]) > maxLength)
        {
            maxLength = strlen(strArray[i]);
            index = i;
        }
    }
    return index;
}

        