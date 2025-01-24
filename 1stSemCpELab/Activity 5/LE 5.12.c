/*
============================================================================
FILE : LE5_12.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Passscode Lock: The program prompts the user for the correct password
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-05-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

#define MAX_ATTEMPTS 3
#define CORRECT_PASSCODE 2410

int main(void) {
    int attempts = 0;
    int inputPasscode = 0;
    int accessGranted = 0;

    printf("You have %d attempts to enter the correct passcode.\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS && !accessGranted) {
        promptUserForPasscode(&inputPasscode);

        if (checkPasscode(inputPasscode)) {
            accessGranted = 1;
        } else {
            attempts++;
            displayAttemptsRemaining(attempts);
        }
    }

    displayAccessMessage(accessGranted);

    return 0;
}