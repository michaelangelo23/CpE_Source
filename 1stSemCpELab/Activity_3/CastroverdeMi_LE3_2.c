/*
============================================================================
FILE : LE3_2.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : This program/function sums the last and second-to-last digits of the provided number
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date:2024-09-05 By: Mickel Angelo Castroverde Description: Finished the project and added comments

============================================================================
*/
#include <stdio.h>
#define WEEKS_IN_YEAR 52

int main() {

    int number, lastDigit, secondLastDigit, sum;

    printf("Enter a number : ");
    scanf("%d", &number);
// this part here will compute to determine the last digit and second to the last digit
    lastDigit = number % 10;
    secondLastDigit = (number / 10) % 10;
    sum = lastDigit + secondLastDigit; // this will add the last and second to the last digits

    printf("Sum: %d + %d = %d", secondLastDigit, lastDigit, sum);
    return 0;
}
