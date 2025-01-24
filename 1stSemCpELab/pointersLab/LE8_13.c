/*
============================================================================
FILE : LE8_13.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Maximum Number

Create a function that determine and returns the maximum number in an array
of integers using pointers. The function accepts the starting address of the
array and number of entries.


      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/

#include <stdio.h>

int findMax(int *arr, int size); // protoype of the function

int main()
{
    int size;

    printf("Enter number of entries: "); // user input
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) // logic of the loop
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, size); // function call
    printf("Maximum Number: %d\n", max); // output

    return 0;
}

int findMax(int *arr, int size) // function definition
{
    int max = *arr;  // initialization of max
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max) // logic of the loop
        {
            max = *(arr + i);
        }
    }
    return max;
}