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
    int decimalNumber, remainder;
    int place = 1;

    printf("Enter a decimal number: "); // ask user for input
    scanf("%d", &decimalNumber);

    printf("Hexadecimal: ");
    while (decimalNumber != 0) { // converting decimal to hexadecimal
        remainder = decimalNumber % 16;

        char hexDigit;  // Convert remainder to hexadecimal digit
        if (remainder < 10) {
            hexDigit = '0';
            for (int j = 0; j < remainder; j++) {
                hexDigit++;
            }
        }
        else
        {
            switch (remainder) {   // decimal to hexadicimal conversion using switch
                case 10: hexDigit = 'A'; break;
                case 11: hexDigit = 'B'; break;
                case 12: hexDigit = 'C'; break;
                case 13: hexDigit = 'D'; break;
                case 14: hexDigit = 'E'; break;
                case 15: hexDigit = 'F'; break;
            }
        }
        printf("%c", hexDigit); // Print the hex digit directly

        decimalNumber = decimalNumber / 16;
    }
    printf("\n");

    return 0;
}
