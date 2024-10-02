/*
============================================================================
FILE : LE5_11.cpp
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Calculates the average of even numbers and product of odd numbers
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
Date: 09-05-24 By: Mickel Angelo Castroverde Description: finished the project
============================================================================
*/
#include <stdio.h>

int main() {
    int num, i;  
    int evenCounter = 0, evenSum = 0;
    long long oddProduct = 1;

    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++) {  
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num % 2 == 0) {
            evenSum += num;
            evenCounter++;
        } else {
            oddProduct *= num;
        }
    }

    if (evenCounter > 0) {
        float even_average = (float)evenSum / evenCounter;
        printf("Average of even numbers: %.2f\n", even_average);
    } else {
        printf("No even numbers entered.\n");
    }

    if (oddProduct <= 1) {
        printf("Product of odd numbers: %lld\n", oddProduct);
    } else {
        printf("No odd numbers entered.\n");
    }

    return 0;
}