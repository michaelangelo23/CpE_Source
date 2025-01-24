/*
============================================================================
FILE : LE4_13.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Calculates the student's final grade and indicate whether it is a passing or a failing grade.
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-12-24 By: Mickel Angelo Castroverde Description: Finished the project
============================================================================
*/
#include <stdio.h>

int main() {
    float mark1, mark2, mark3, mark4;

    printf("1st Mark : ");
    scanf("%f", &mark1);

    printf("2nd Mark : ");
    scanf("%f", &mark2);

    printf("3rd Mark : ");
    scanf("%f", &mark3);

    printf("4th Mark : ");
    scanf("%f", &mark4);

    // check for invalid input
    if (mark1 < 0 || mark1 > 100 || mark2 < 0 || mark2 > 100 ||
        mark3 < 0 || mark3 > 100 || mark4 < 0 || mark4 > 100) {
        printf("INVALID INPUT!\n");
    } else {
        // calculate the average
        float finalGrade = (mark1 + mark2 + mark3 + mark4) / 4;

        // print the average
        printf("FINAL GRADE: %.2f\tREMARKS : ", finalGrade);

        // check for finalGrade if it is greater, equal or less than 50
        if (finalGrade >= 50) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }

        //separator
        printf("================================================================================\n");
    }

    return 0;
}
