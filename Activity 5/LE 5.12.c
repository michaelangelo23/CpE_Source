#include <stdio.h>

#define MAX_ATTEMPTS 3
#define CORRECT_PASSCODE 2410

int main() {
    int attempts = 0;
    int inputPasscode;
    int accessGranted = 0;

    printf("You have %d attempts to enter the correct passcode.\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS && !accessGranted) {
        printf("Enter the passcode: ");
        scanf("%d", &inputPasscode);

        if (inputPasscode == CORRECT_PASSCODE) {
            accessGranted = 1;
        } else {
            attempts++;
            if (attempts < MAX_ATTEMPTS) {
                printf("Incorrect passcode. %d attempts remaining.\n\n", MAX_ATTEMPTS - attempts);
            }
        }
    }

    if (accessGranted) {
        printf("\nACCESS GRANTED\n");
    } else {
        printf("\nACCESS DENIED\n");
    }

    return 0;
}