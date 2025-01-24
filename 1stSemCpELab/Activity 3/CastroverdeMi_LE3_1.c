
/*
============================================================================

FILE : LE3_1.c
AUTHOR : Mickel Angelo Castroverde
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved. 
DESCRIPTION : Calculates the user's weekly pay from his/her yearly salary
COPYRIGHT : created
REVISION HISTORY
Date:09/05.24 By:Mickel Angelo Castroverde Description: finished the project

============================================================================
*/

#include <stdio.h>
#define WEEKS_IN_YEAR 52

int main() {

    int userYearlyPay;

    printf("What is your yearly pay: "); //prompts the user for their yearly pay
    scanf("%d", &userYearlyPay);

    float weeklyPay = userYearlyPay / WEEKS_IN_YEAR;
    printf("Your weekly pay is %.2f", weeklyPay);
    return 0;
}
