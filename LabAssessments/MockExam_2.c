/*
============================================================================
FILE : mockExam_2.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : mockeExam number 2 for MIdeterms
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
|Date: nn/nn/nn |By: Mickel Angelo Castroverde |Description: finished and commented the code
============================================================================
*/
#include <stdio.h>

int main() 
{
    int decimalNumber, remainder, i = 0;
    char hexDigits[100];

    printf("Enter a decimal number: "); // Read decimal number from user
    scanf("%d", &decimalNumber);

    while (decimalNumber != 0) { // Convert decimal to hexadecimal
        remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexDigits[i] = 48 + remainder; // ASCII value of digits 0-9
        } else {
            hexDigits[i] = 55 + remainder; // ASCII value of letters A-F
        }
        decimalNumber = decimalNumber / 16;
        i++;
    }
    
    printf("Hexadecimal: ");  // Print hexadecimal number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexDigits[j]);
    }
    printf("\n");

    return 0;
}
