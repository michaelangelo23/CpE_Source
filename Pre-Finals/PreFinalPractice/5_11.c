/*
============================================================================
FILE : preFinalPractice.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Even and Odd
    average of all even numbers  // product of all odd numbers
            

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/
#include <stdio.h>

void ifOddOrEven(int num, long long oddProduct, int evenCounter, int evenSum);

int main()
{
    int num, i;  
    int evenCounter = 0, evenSum = 0;
    long long oddProduct = 1; // initialize to 1 to avoid multiplying by 0

    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++)
    {  
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            evenSum += num;
            evenCounter++;    // if number is even increment counter
        }
        else
        {
            oddProduct *= num;
        }
    }

    void ifOddOrEven(int num, long long oddProduct, int evenCounter, int evenSum);

    return 0;
}

void ifOddOrEven(int num, long long oddProduct, int evenCounter, int evenSum)
{
    if (evenCounter > 0)
    {
        float even_average = (float)evenSum / evenCounter;
        printf("Average of even numbers: %.2f\n", even_average);
    }
    else
    {
        printf("No even numbers entered.\n");
    }

    if (oddProduct <= 1)
    {
        printf("Product of odd numbers: %lld\n", oddProduct);
    }
    else
    {
        printf("No odd numbers entered.\n");
    }
}


