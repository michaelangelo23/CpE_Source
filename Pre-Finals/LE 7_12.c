/*
============================================================================
FILE : LE7_12.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :

                    Vowels and Consonants in String
        Ask a string and determine how many vowels and consonants

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/

#include <stdio.h>
#include <string.h>

void countVowelsAndConso(char str[]);      // function for counting vowels and consonants

int main()
{
    char str[100];                     // array to store the input string
    int validInput = 0;               // flag to check if input is valid

    while (!validInput)
    {
        printf("Enter a string: ");       // prompt user to enter a string
        fgets(str, sizeof(str), stdin);  // read the input string from the user

        validInput = 1;                // assuming input is valid
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9')    // check if the character is a digit
            { 
                printf("Invalid input. Please enter a string without numbers.\n");  // input is not valid
                validInput = 0; 
                break;
            }
        }
    }

    countVowelsAndConso(str);      // call function to count vowels and consonants
    return 0; 
}

 /*
============================================================================
 FUNCTION    : countVowelsAndConso
 DESCRIPTION : Counts the number of vowels and consonants in a string
 ARGUMENTS   : char str[] - input string
 RETURNS     : void
===========================================================================
*/

void countVowelsAndConso(char str[])           // function to count vowels and consonants in a string
{
    int vowels = 0, consonants = 0;         // variables to store the count of vowels and consonants
    int i; // Loop counter

    for(i = 0; str[i] != '\0'; i++)     // count vowels and consonants
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))  // check if character is a letter
        { 
            if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || 
               str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || 
               str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || 
               str[i] == 'u') 
               {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}


