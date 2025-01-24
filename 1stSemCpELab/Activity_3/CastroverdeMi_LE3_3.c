/*
============================================================================
FILE : LE3_3.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : This program calculates the tuition fees for two semesters at
           5 By: Mickel Angelo Castroverde Description: Finished the project and added comments
Date:2024-09-09 By: Assistant Description: Implemented inline calculation without separate function

============================================================================
*/
#include <stdio.h>

#define REGISTRATION_FEE 450
#define UNIT_FEE 450
#define PENALTY_FEE 2260
#define PENALTY_UNITS 12  // constants for fee calculation

int main() {
    // variables for unit counts and tuition fees
    int firstSemUnits, secondSemUnits;
    float firstSemTuition, secondSemTuition, totalTuition;

    // prompt user for semester units and read inputs
    printf("1st Semester Number of Units: ");
    scanf("%d", &firstSemUnits);

    printf("2nd Semester Number of Units: ");
    scanf("%d", &secondSemUnits);

    // calculation for the first semester
    firstSemTuition = REGISTRATION_FEE + (firstSemUnits * UNIT_FEE);
    float firstSemPenalty = (float) firstSemUnits / PENALTY_UNITS;
    firstSemTuition += firstSemPenalty * PENALTY_FEE;

    // calculation for the second semester
    secondSemTuition = REGISTRATION_FEE + (secondSemUnits * UNIT_FEE);
    float secondSemPenalty = (float) secondSemUnits / PENALTY_UNITS;
    secondSemTuition += secondSemPenalty * PENALTY_FEE;

    // calculate total tuition
    totalTuition = firstSemTuition + secondSemTuition;

    // output for calculated fees formatted to two decimals
    printf("1st Semester Tuition Fee    : %.2f\n", firstSemTuition);
    printf("2nd Semester Tuition Fee    : %.2f\n", secondSemTuition);
    printf("Total Tuition Fee           : %.2f\n", totalTuition);

    return 0;
}
