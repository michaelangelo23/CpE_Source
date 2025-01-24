/*
============================================================================
FILE : mockPreFinals.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                        MOCK EXAM 1 PRE-FINALS

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-12-24 By: Mickel Angelo Castroverde
Description: Done and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/
#include <stdio.h>

#define LBS_TO_KG 0.453592
#define INCH_TO_M 0.0254

float getHeight();
float getWeight();
float calcBMI(float weight, float height);
void classifyBMI(float bmi);

int main() 
{
    float bmi, ht, wt;
   
    ht = getHeight();
    wt = getWeight();
    bmi = calcBMI(wt, ht);
    classifyBMI(bmi);
        
    return 0;
}

float getHeight()
{
    float height;
    printf("Enter height in inches: ");
    scanf("%f", &height);
    return height;
}

float getWeight()
{
    float weight;
    printf("Enter weight in pounds: ");
    scanf("%f", &weight);
    return weight;
}

float calcBMI(float weight, float height) {
    weight = weight * LBS_TO_KG;
    height = height * INCH_TO_M;
    return weight / (height * height);
}

void classifyBMI(float bmi) {
    printf("\nBMI Factor = %.2f", bmi);

    if (bmi >= 30.0)
    {
        printf("\nObesity");
    }
    else if (bmi >= 25.0 && bmi < 30.0)
    {
        printf("\nOverweight");
    } else if (bmi >= 18.5 && bmi < 25.0) {
        printf("\nNormal weight");
    } else {
        printf("\nUnderweight");
    }
}