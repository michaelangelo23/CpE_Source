/*
============================================================================
FILE : LE4_11.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Vowel and Consonant Checker. This program repeatedly takes letter
              inputs from the user and determines whether each is a vowel,
              consonant, or an invalid input.
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-05-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

int main() {

    char inputLetter;

    printf("Enter a letter: ");
    scanf("%c", &inputLetter);

    // Check if the entered character is an alphabetic letter (either uppercase A-Z or lowercase a-z)
    if ((inputLetter >= 'A' && inputLetter <= 'Z') || (inputLetter >= 'a' && inputLetter <= 'z')) {

        // If the letter is uppercase (A-Z), convert it to lowercase by adding 32 to its ASCII value
        if (inputLetter >= 'A' && inputLetter <= 'Z') { //if inputLetter is 'A' (code 65), adding 32 results in 97, which is the code for 'a'.
            inputLetter = inputLetter + 32;
        }

        // Check if the letter (now lowercase) is a vowel
        if (inputLetter == 'a' || inputLetter == 'e' || inputLetter == 'i' || inputLetter == 'o' || inputLetter == 'u') {
            printf("VOWEL!\n");  // If vowel, print "VOWEL!"
        } else {
            printf("CONSONANT!\n");  // If not a vowel, print "CONSONANT!"
        }
    } else {
        // If not a letter, print "INVALID INPUT!"
        printf("INVALID INPUT!\n");
    }

    printf("==========================================\n");
    return 0;
}
