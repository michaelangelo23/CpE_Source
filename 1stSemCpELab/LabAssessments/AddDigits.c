/*
============================================================================
FILE : 6_11.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Add Digits
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
|Date: 10-08-24 |By: Mickel Angelo Castroverde |Description: finished and commented the code
============================================================================
*/
#include <stdio.h>
#include <math.h>

#define REMAINDER 10 // constant for the remainder

int extractFirstLSD(int num);
int extractSecondLSD(int num);
int sumDigits(int num1, int num2);

int main()
{   int num, sum, num1, num2;
    // prompts and gets user input
    printf("Enter an number:");
    scanf("%d", &num);

    num1 = extractFirstLSD(num); // extracts the first least significant digit
    num2 = extractSecondLSD(num); // extracts the second least significant digit
    sum = sumDigits(num1, num2);  // sums the two digits

    printf("\nSum\t   :%d + %d = %d\n", num2, num1, sum); // prints the sum
    return 0;
}

// function to extract the first least significant digit
int extractFirstLSD(int num)  
{
    return num % REMAINDER ;  // returns the remainder of the number divided by 10
}

// function to extract the second least significant digit
int extractSecondLSD(int num) 
{
    return (num / REMAINDER) % REMAINDER; // returns the remainder of the number divided by 10
}

// function to sum the two digits
int sumDigits(int num1, int num2)
{
    return num1 + num2; // function to sum the two digits
}
